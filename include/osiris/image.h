#ifndef _OSIRIS_IMAGE_H_
#define _OSIRIS_IMAGE_H_

struct _Image {

	int w;
	int h;
	int c;
	float *data;

};

typedef struct _Image Image;

extern Image *image_new (void);

extern void image_delete (void *image_ptr);

extern Image *image_create (
	int w, int h, int c
);

extern Image *image_load_mem (
	const unsigned char *buffer, int buffer_len,
	int w, int h, int c
);

extern Image *image_load (
	const char *filename, int w, int h, int c
);

extern Image *image_load_color (
	const char *filename, int w, int h
);

#endif