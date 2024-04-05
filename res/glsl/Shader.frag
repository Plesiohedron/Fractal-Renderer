#version 460 core

/*
out vec4 color;

const int MAX_ITERATIONS = 255;
const int SQUARE_MAX_LENGTH = 2 * 2;

dvec2 function(dvec2 z, dvec2 c) {
	return dvec2(z.x * z.x - z.y * z.y + c.x, 2 * z.x * z.y + c.y);
}

double square_modulus(dvec2 z) {
	return z.x * z.x + z.y * z.y;
}

void main() {
	dvec2 z = gl_FragCoord.xy / dvec2(1280, 720);
	dvec2 c = dvec2(-1.0, 0);
	vec3 fractal_color = vec3(0.0f);

	for (int i = 0; i < MAX_ITERATIONS; ++i) {
		z = function(z, c);

		if (square_modulus(z) > SQUARE_MAX_LENGTH) {
			fractal_color = vec3(1);
			break;
		}
	
	}

	color = vec4(fractal_color, 1);
}
*/

out vec4 color;

void main() {
	color = vec4(1, 1, 1, 1);
}