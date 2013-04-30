
//////////////////////////////////////////////////////////////
// akshar_callbacks.h - All Callbacks Setup and Called Here //
//////////////////////////////////////////////////////////////

#ifndef AKSHAR_CALLBACKS_H
#define AKSHAR_CALLBACKS_H

#include "akshar_ui.h"
#include "akshar_utils.h"

// Callback Prototypes //////////////////////////////////////

static gboolean newItemHandler(GtkWidget *, GdkEvent *);
static gboolean openItemHandler(GtkWidget *, GdkEvent *);
static gboolean saveItemHandler(GtkWidget *, GdkEvent *);
static gboolean saveAsItemHandler(GtkWidget *, GdkEvent *);
static gboolean exitItemHandler(GtkWidget *, GdkEvent *);
static gboolean cutItemHandler(GtkWidget *, GdkEvent *);
static gboolean copyItemHandler(GtkWidget *, GdkEvent *);
static gboolean pasteItemHandler(GtkWidget *, GdkEvent *);
static gboolean prefsItemHandler(GtkWidget *, GdkEvent *);
static gboolean runItemHandler(GtkWidget *, GdkEvent *);
static gboolean cancelRunItemHandler(GtkWidget *, GdkEvent *);
static gboolean helpMeItemHandler(GtkWidget *, GdkEvent *);
static gboolean aboutItemHandler(GtkWidget *, GdkEvent *);

// Function Prototypes //////////////////////////////////////

static gboolean createDb(const char *); 	// Return: TRUE on create successful; FALSE otherwise
static gboolean openDb(const char *); 		// Return: TRUE on open successful; FALSE otherwise
static gboolean writeDb();                // Return: TRUE on write successful; FALSE otherwise
void sqlEngine();              						// Main SQL Engine

void setup_callbacks() {
	
	// Exits the application when X button is clicked
	g_signal_connect(window,"destroy",G_CALLBACK(gtk_main_quit),NULL);
	
	// Application menu connect callbacks
	g_signal_connect_swapped(newItem,"activate",G_CALLBACK(newItemHandler),fileMenu);
	g_signal_connect_swapped(openItem,"activate",G_CALLBACK(openItemHandler),fileMenu);
	g_signal_connect_swapped(saveItem,"activate",G_CALLBACK(saveItemHandler),fileMenu);
	g_signal_connect_swapped(saveAsItem,"activate",G_CALLBACK(saveAsItemHandler),fileMenu);
	g_signal_connect(exitItem,"activate",G_CALLBACK(gtk_main_quit),NULL);
	g_signal_connect_swapped(cutItem,"activate",G_CALLBACK(cutItemHandler),editMenu);
	g_signal_connect_swapped(copyItem,"activate",G_CALLBACK(copyItemHandler),editMenu);
	g_signal_connect_swapped(pasteItem,"activate",G_CALLBACK(pasteItemHandler),editMenu);
	g_signal_connect_swapped(prefsItem,"activate",G_CALLBACK(prefsItemHandler),editMenu);
	g_signal_connect_swapped(runItem,"activate",G_CALLBACK(runItemHandler),editMenu);
	g_signal_connect_swapped(cancelRunItem,"activate",G_CALLBACK(cancelRunItemHandler),editMenu);
	g_signal_connect_swapped(helpMeItem,"activate",G_CALLBACK(helpMeItemHandler),helpMenu);
	g_signal_connect_swapped(aboutItem,"activate",G_CALLBACK(aboutItemHandler),helpMenu);
	
	// Application toolbar connect callbacks
	g_signal_connect(G_OBJECT(tbNew), "clicked", G_CALLBACK(newItemHandler), NULL);
	g_signal_connect(G_OBJECT(tbOpen), "clicked", G_CALLBACK(openItemHandler), NULL);
	g_signal_connect(G_OBJECT(tbSave), "clicked", G_CALLBACK(saveItemHandler), NULL);
	g_signal_connect(G_OBJECT(tbSaveAs), "clicked", G_CALLBACK(saveAsItemHandler), NULL);
	g_signal_connect(G_OBJECT(tbCut), "clicked", G_CALLBACK(cutItemHandler), NULL);
	g_signal_connect(G_OBJECT(tbCopy), "clicked", G_CALLBACK(copyItemHandler), NULL);
	g_signal_connect(G_OBJECT(tbPaste), "clicked", G_CALLBACK(pasteItemHandler), NULL);
	g_signal_connect(G_OBJECT(tbPrefs), "clicked", G_CALLBACK(prefsItemHandler), NULL);
	g_signal_connect(G_OBJECT(tbRun), "clicked", G_CALLBACK(runItemHandler), NULL);
	g_signal_connect(G_OBJECT(tbCancelRun), "clicked", G_CALLBACK(cancelRunItemHandler), NULL);
}

// Callbacks //////////////////////////////////////////

static gboolean newItemHandler(GtkWidget *widget,GdkEvent *event) {

	createDb("test.adb");
	return TRUE;
}
static gboolean openItemHandler(GtkWidget *widget,GdkEvent *event) {
	return TRUE;
}
static gboolean saveItemHandler(GtkWidget *widget,GdkEvent *event) {
	return TRUE;
}
static gboolean saveAsItemHandler(GtkWidget *widget,GdkEvent *event) {
	return TRUE;
}
static gboolean cutItemHandler(GtkWidget *widget,GdkEvent *event) {
	return TRUE;
}
static gboolean copyItemHandler(GtkWidget *widget,GdkEvent *event) {
	return TRUE;
}
static gboolean pasteItemHandler(GtkWidget *widget,GdkEvent *event) {
	return TRUE;
}
static gboolean prefsItemHandler(GtkWidget *widget,GdkEvent *event) {
	
	msgbox("DEBUG: You clicked Preference!");
	return TRUE;
}
static gboolean runItemHandler(GtkWidget *widget,GdkEvent *event) {
	
	msgbox("DEBUG: You clicked Execute!");
	return TRUE;
}
static gboolean cancelRunItemHandler(GtkWidget *widget,GdkEvent *event) {
	
	msgbox("DEBUG: You clicked Cancel Execute!");
	return TRUE;
}
static gboolean helpMeItemHandler(GtkWidget *widget,GdkEvent *event) {
	return TRUE;
}
static gboolean aboutItemHandler(GtkWidget *widget,GdkEvent *event) {
	return TRUE;
}

// Logic Functions //////////////////////////////////////

/* DB File Structure
   -----------------
   - 'Map Table Pointer' - 10 byte String pointing to offset of the 'Map Table'
   - The 'Data Section'. Initially 1 byte in size
   - The 'Holes Table'. Each entry- offset of the gap in 'Data Section' (10 bytes)
       and length of the gap in bytes (10 bytes)
   - The 'Map Table'. Holds the starting points of every cluster of a table
 */
 
static gboolean createDb(const char *fileName) {
	
	dbFile = fopen(fileName, "w");
	
	/* Map Table Pointer
	*/
	sprintf(buffer, "0000000012");  // 12 at start
	
	/* Data Section
	   ------------
	   Data Section is made of "Table Clusters". Each cluster holds some amount of
	   data for a table. Multiple scattered clusters can exist for a table most probably
	   because of data being added later to an existing table.
	   
	   [Hypothetical Scenario: Fields for every data type in a Table]
		   - Table..
		     ---------------------------------------------------------
		     | Code | Data Type                                      |
		     ---------------------------------------------------------
		   	 | 01   | CHAR        _/ Data Offset Address  (10 Bytes),|
		   	 | 02   | BINARY       \ Data Length in bytes (10 Bytes) |
		   	 | 03   | INT         _/ Constant Space                  |
		   	 | 04   | FLOAT        \                                 |
		   	 | 05   | DATETIME                                       |
		   	 ---------------------------------------------------------
		   - Table..
		   - Table..
		   - .......
		 
		 The "Code" takes 2 bytes of space before a field entry. For Reference type fields Char
		 and Binary they are placed before Offset Address+Data Length=20 bytes. For Value type
		 fields these 2 bytes are placed before the data.
	*/
	sprintf(temp,"%d", 0);
	strncat(buffer, temp, strlen(temp));
	
	/* The Map Section
	   ---------------
		 - For Each Table Cluster Entry (Could be more than one entry for one table):
		 	 - [Table Cluster Offset Address (10 bytes)]
		 	 - [Table Cluster Length in bytes (10 bytes)]
	*/
	
	fwrite(buffer, strlen(buffer), sizeof(char), dbFile);
	
	fclose(dbFile);
	return TRUE;
}

#endif

