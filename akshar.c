#include "akshar.h"
#include "akshar_ui.h"
#include "akshar_callbacks.h"
#include "akshar_logic.h"

int main(int argc,char **argv) {

	// Initialize GTK
	gtk_init(&argc,&argv);
	
	// UI Setup Functions from 'akshar_ui.h'
	setup_ui();
	
	// Callback Functions from 'akshar_callbacks.h'
	setup_callbacks();
	
	// Business Logic from 'akshar_logic.h'
	run_program();
	
	// The Application Loop. Here We Go! :D
	gtk_main();
	return 0;
}

