#version 460 core

uniform dvec2 scale;
uniform dvec2 window_size;
uniform dvec2 offset;
uniform dvec2 C;

uniform sampler2D texture0;

out vec4 color;

const int MAX_ITERATIONS = 255;
const int SQUARE_MAX_LENGTH = 4 * 4;

const dvec2 CENTER_OFFSET = dvec2(0.5, 0.5);

dvec2 function(dvec2 z, dvec2 c) {
	return dvec2(z.x * z.x - z.y * z.y + c.x, 2 * z.x * z.y + c.y);
}

double square_modulus(dvec2 z) {
	return z.x * z.x + z.y * z.y;
}

void main() {
	dvec2 Z = (gl_FragCoord.xy / window_size - CENTER_OFFSET) / scale + offset / window_size;
	vec4 fractal_color = texture(texture0, vec2(0.5, 0.5));

	for (int i = 0; i < MAX_ITERATIONS; ++i) {
		Z = function(Z, C);

		if (square_modulus(Z) > SQUARE_MAX_LENGTH) {
			fractal_color = vec4(i / MAX_ITERATIONS, i / MAX_ITERATIONS, i / MAX_ITERATIONS, 1);
			break;
		}
	}

	color = fractal_color;
}