#include <stdlib.h>

#include "osiris/image.h"

#define STB_IMAGE_IMPLEMENTATION
#include "osiris/stb/stb_image.h"

Image *image_new (void) {

	Image *image = (Image *) malloc (sizeof (Image));
	if (image) {
		image->w = 0;
		image->h = 0;
		image->c = 0;

		image->data = NULL;
	}

	return image;

}

void image_delete (void *image_ptr) {

	if (image_ptr) {
		Image *image = (Image *) image_ptr;

		if (image->data) free (image->data);

		free (image);
	}

}

Image *image_create (int w, int h, int c) {

	Image *image = image_new ();
	if (image) {
		image->w = w;
		image->h = h;
		image->c = c;

		image->data = (float *) calloc (h * w * c, sizeof (float));
	}

	return image;

}

static Image *image_make (
	unsigned char *data,
	int w, int h, int c
) {

	Image *image = image_create (w, h, c);

	if (image) {
		int dst_index = 0;
		int src_index = 0;
		for (int k = 0; k < c; ++k) {
			for (int j = 0; j < h; ++j) {
				for (int i = 0; i < w; ++i) {
					dst_index = i + w * j + w *h * k;
					src_index = k + c * i + c * w * j;
					image->data[dst_index] = (float) data[src_index] / 255.0;
				}
			}
		}
	}

	return image;

}

static Image *image_load_mem_stb (
	const unsigned char *buffer, int buffer_len, int channels
) {

	Image *image = NULL;

	if (buffer) {
		int w, h, c;
		unsigned char *data = stbi_load_from_memory (
			buffer, buffer_len,
			&w, &h, &c, channels
		);
		if (data) {
			if (channels) c = channels;

			image = image_make (data, w, h, c);

			free (data);
		}

		else {
			osiris_log_error ("Failed to load image from file!");
			#ifdef OSIRIS_DEBUG
			fprintf (stderr, "STB Reason: %s\n", stbi_failure_reason ());
			#endif
		}
	}

	return image;

}

Image *image_load_mem (
	const unsigned char *buffer, int buffer_len,
	int w, int h, int c
) {

	Image *image = NULL;

	if (buffer) {
		image = image_load_mem_stb (buffer, buffer_len, c);

		// TODO: resize image if needed
		// if ((h && w) && (h != out.h || w != out.w)){
		//     image resized = resize_image(out, w, h);
		//     free_image(out);
		//     out = resized;
		// }
	}

	return image;

}

static Image *image_load_stb (
	const char *filename, int channels
) {

	Image *image = NULL;

	if (filename) {
		int w, h, c;
		unsigned char *data = stbi_load (filename, &w, &h, &c, channels);
		if (data) {
			if (channels) c = channels;

			image = image_make (data, w, h, c);

			free (data);
		}

		else {
			(void) fprintf (stderr, "Failed to load image from file!");
			#ifdef OSIRIS_DEBUG
			(void) fprintf (
				stderr, "STB Reason: %s\n", stbi_failure_reason ()
			);
			#endif
		}
	}

	return image;

}

Image *image_load (const char *filename, int w, int h, int c) {

	Image *image = NULL;

	if (filename) {
		image = image_load_stb (filename, c);

		// TODO: resize image if needed
		// if ((h && w) && (h != out.h || w != out.w)){
		//     image resized = resize_image(out, w, h);
		//     free_image(out);
		//     out = resized;
		// }
	}

	return image;

}

Image *image_load_color (const char *filename, int w, int h) {

	return filename ? image_load (filename, w, h, 3) : NULL;

}