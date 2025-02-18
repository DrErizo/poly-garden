#version 330 core
out vec4 FragColor;
precision mediump float;
in vec3 sPos;

vec2 center = vec2(500,500);
void main(){
//    FragColor = vec4(gl_FragCoord.xyz, 1.0f);
	float dist = distance(center, gl_FragCoord.xy);
	if(dist > 200){
		discard;
		//FragColor = vec4(0,0,0,1.0 );
	}else{
		FragColor = vec4(0.4f,0.3f,0.7f, 1.0 );
	}
}

