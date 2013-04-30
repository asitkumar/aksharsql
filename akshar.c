#include "akshar.h"
#include "akshar_ui.h"
#include "akshar_callbacks.h"

int main(int argc,char **argv) {

	// Initialize GTK
	gtk_init(&argc,&argv);
	
	// Initial Allocations
	buffer = (char *) malloc(1000);
	temp = (char *) malloc(1000);
	
	// UI Setup Functions from 'akshar_ui.h'
	setup_ui();
	
	// Callback Functions from 'akshar_callbacks.h'
	setup_callbacks();
	
	// The Application Loop. Here We Go! :D
	gtk_main();
	
	// Free Memory
	free(temp);
	free(buffer);
	
	return 0;
}

