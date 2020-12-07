#include <cerver/utils/log.h>

#include "version.h"

// print full osiris version information
void osiris_version_print_full (void) {

	cerver_log_msg ("\n\nOsiris Mini Version: %s\n", OSIRIS_MINI_VERSION_NAME);
	cerver_log_msg ("Release Date & time: %s - %s\n", OSIRIS_MINI_VERSION_DATE, OSIRIS_MINI_VERSION_TIME);
	cerver_log_msg ("Author: %s\n\n", OSIRIS_MINI_VERSION_AUTHOR);

}

// print the version id
void osiris_version_print_version_id (void) {

	cerver_log_msg ("\n\nOsiris Mini Version ID: %s\n", OSIRIS_MINI_VERSION);

}

// print the version name
void osiris_version_print_version_name (void) {

	cerver_log_msg ("\n\nOsiris Mini Version: %s\n", OSIRIS_MINI_VERSION_NAME);

}