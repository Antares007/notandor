/** made by Matthias Hurrle (@atzedent) */
/** @type {HTMLElement} */
const canvas = window.canvas;
const gl = canvas.getContext("webgl2");
const dpr = Math.max(1, 0.5 * window.devicePixelRatio);
/** @type {Map<string,PointerEvent>} */
const touches = new Map();

const vertexSource = `#version 300 es
#ifdef GL_FRAGMENT_PRECISION_HIGH
precision highp float;
#else
precision mediump float;
#endif

in vec2 position;

void main(void) {
    gl_Position       = vec4(position, 0., 1.);
}
`;
const fragmentSource = `#version 300 es
/*********
* made by Matthias Hurrle (@atzedent)
*/

#ifdef GL_FRAGMENT_PRECISION_HIGH
precision highp float;
#else
precision mediump float;
#endif

uniform float time;
uniform vec2 resolution;
uniform vec2 touch;
uniform int pointerCount;

out vec4 fragColor;

#define T (mod(time+5., 200.))
#define S smoothstep
#define mouse (touch/resolution)
#define rot(a) mat2(cos(a),-sin(a),sin(a),cos(a))
float oct(vec3 p, float s) {
    p = abs(p);

    return (p.x+p.y+p.z-s)*(1./sqrt(3.));
}

float mat=1.;
float map(vec3 p) {
    vec3 q = p;
    q.xz *= rot(-T*.5);
    q.yz *= rot(T*.25);
    float d = 1e5,
    oc0=oct(q, 1.75),
    flr = p.y+3.+sin(T+p.x+sin(p.xz*rot(.5678)).x)*.5;

    d=min(d,oc0);
    d=min(d,flr);
    
    if(d==oc0) mat=.0;
    else mat=1.;

    return d;
}

vec3 norm(vec3 p) {
    vec2 e=vec2(1e-2,0);
    float d=map(p);
    vec3 n=d-vec3(
        map(p-e.xyy),
        map(p-e.yxy),
        map(p-e.yyx)
    );

    return normalize(n);
}

float getshadow(vec3 ro, vec3 rd) {
    const float steps=10., k=64.;
    float shade=1.;

    for(float i=1e-3;i<steps;) {
        float d=map(ro+rd*i);

        if(d<1e-3) {
            shade=5e-3;
            break;
        }

        shade=min(shade, k*d/i);

        i+=d;
    }

    return shade;
}

float getao(vec3 p, vec3 n, float dist) {
    return clamp(map(p+n*dist)/dist,.0,1.);
}

void cam(inout vec3 p) {
    if(pointerCount>0) {
        p.yz*=rot(-clamp(mouse.y,-1.,.5)*acos(-1.)+acos(.0));
        p.xz*=rot(-mouse.x*acos(-1.)*2.);
    } else {
        p.yz*=rot(sin(T*.5)*.25+.25);
        p.xz*=rot(T*.25);
        p.xy*=rot(sin(T*.5)*.25+.25);
    }
}

void main(void) {
    vec2 uv = (
        gl_FragCoord.xy-.5*resolution.xy
    )/min(resolution.x,resolution.y);

    vec3 col = vec3(0),
    ro=vec3(0,0,2.*exp(-cos(T*.25))-10.),
    rd=normalize(vec3(uv,1));

    cam(ro);
    cam(rd);

    vec3 p=ro,
    l=normalize(vec3(1,2,3));

    const float steps=100.,maxd=20.;
    float i=.0, dd=.0, edge=.0;
    bool near=false;

    for(;i<steps;i++) {
        float d=map(p)*.5;

        if(d<1e-3) break;

        if(near && d>3e-2) {
            edge=1.;
            break;
        }

        if(d<2e-2) {
            near=true;
        }

        if(dd>maxd) {
            dd=maxd;
            break;
        }

        p+=rd*d;
        dd+=d;
    }

    vec3 n=norm(p);

    float
    fog=1.-clamp(dd/maxd,.0,1.),
    fnl=max(.0,dot(-rd,n)),
    sha=getshadow(p+n*5e-2,l),
    ao=getao(p,n,.05);

    col+=fog*pow(fnl,3.);
    if(mat==1.) col*=sha;
 
    if(ao<.9) edge=max(edge,max(fog, 1.));
    ao=getao(p,n,-.05);
    if(ao<.9) edge=max(edge,max(fog, 1.));
    col = mix(col,vec3(0),pow(S(.0,1.,edge),5.));

    col = pow(col, vec3(.4545));
    col = S(1.,.0,exp(-col*8.));
    col = abs(col);

    fragColor = vec4(col,1);
}
`;
let time;
let buffer;
let program;
let touch;
let resolution;
let pointerCount;
let vertices = [];
let touching = false;

function resize() {
  const { innerWidth: width, innerHeight: height } = window;

  canvas.width = width * dpr;
  canvas.height = height * dpr;

  gl.viewport(0, 0, width * dpr, height * dpr);
}

function compile(shader, source) {
  gl.shaderSource(shader, source);
  gl.compileShader(shader);

  if (!gl.getShaderParameter(shader, gl.COMPILE_STATUS)) {
    console.error(gl.getShaderInfoLog(shader));
  }
}

function setup() {
  const vs = gl.createShader(gl.VERTEX_SHADER);
  const fs = gl.createShader(gl.FRAGMENT_SHADER);

  program = gl.createProgram();

  compile(vs, vertexSource);
  compile(fs, fragmentSource);

  gl.attachShader(program, vs);
  gl.attachShader(program, fs);
  gl.linkProgram(program);

  if (!gl.getProgramParameter(program, gl.LINK_STATUS)) {
    console.error(gl.getProgramInfoLog(program));
  }

  vertices = [-1.0, -1.0, 1.0, -1.0, -1.0, 1.0, -1.0, 1.0, 1.0, -1.0, 1.0, 1.0];

  buffer = gl.createBuffer();

  gl.bindBuffer(gl.ARRAY_BUFFER, buffer);
  gl.bufferData(gl.ARRAY_BUFFER, new Float32Array(vertices), gl.STATIC_DRAW);

  const position = gl.getAttribLocation(program, "position");

  gl.enableVertexAttribArray(position);
  gl.vertexAttribPointer(position, 2, gl.FLOAT, false, 0, 0);

  time = gl.getUniformLocation(program, "time");
  touch = gl.getUniformLocation(program, "touch");
  pointerCount = gl.getUniformLocation(program, "pointerCount");
  resolution = gl.getUniformLocation(program, "resolution");
}

function draw(now) {
  gl.clearColor(0, 0, 0, 1);
  gl.clear(gl.COLOR_BUFFER_BIT);

  gl.useProgram(program);
  gl.bindBuffer(gl.ARRAY_BUFFER, null);
  gl.bindBuffer(gl.ARRAY_BUFFER, buffer);

  gl.uniform1f(time, now * 0.001);
  gl.uniform2f(touch, ...getTouches());
  gl.uniform1i(pointerCount, touches.size);
  gl.uniform2f(resolution, canvas.width, canvas.height);
  gl.drawArrays(gl.TRIANGLES, 0, vertices.length * 0.5);
}

function getTouches() {
  if (!touches.size) {
    return [0, 0];
  }

  for (let [id, t] of touches) {
    const result = [dpr * t.clientX, dpr * (innerHeight - t.clientY)];

    return result;
  }
}

function loop(now) {
  draw(now);
  requestAnimationFrame(loop);
}

function init() {
  setup();
  resize();
  loop(0);
}

document.body.onload = init;
window.onresize = resize;
canvas.onpointerdown = (e) => {
  touching = true;
  touches.set(e.pointerId, e);
};
canvas.onpointermove = (e) => {
  if (!touching) return;
  touches.set(e.pointerId, e);
};
canvas.onpointerup = (e) => {
  touching = false;
  touches.clear();
};
canvas.onpointerout = (e) => {
  touching = false;
  touches.clear();
};
