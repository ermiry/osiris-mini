#include <stdio.h>

#include "osiris/version.h"

// print full osiris version information
void osiris_version_print_full (void) {

	(void) printf ("\n\nOsiris Mini Version: %s\n", OSIRIS_MINI_VERSION_NAME);
	(void) printf ("Release Date & time: %s - %s\n", OSIRIS_MINI_VERSION_DATE, OSIRIS_MINI_VERSION_TIME);
	(void) printf ("Author: %s\n\n", OSIRIS_MINI_VERSION_AUTHOR);

}

// print the version id
void osiris_version_print_version_id (void) {

	(void) printf ("\n\nOsiris Mini Version ID: %s\n", OSIRIS_MINI_VERSION);

}

// print the version name
void osiris_version_print_version_name (void) {

	(void) printf ("\n\nOsiris Mini Version: %s\n", OSIRIS_MINI_VERSION_NAME);

}