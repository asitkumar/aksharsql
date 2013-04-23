
///////////////////////////////////////////
// akshar_ui.h - All UI Elements Go Here //
///////////////////////////////////////////

#ifndef AKSHAR_UI_H
#define AKSHAR_UI_H

#include "akshar.h"

void setup_ui() {
	
	// Application Main Window and Alignment
	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title(GTK_WINDOW(window),AKSHAR_NAME_VER);
	gtk_window_set_resizable(GTK_WINDOW(window),TRUE);
	gtk_window_set_default_size(GTK_WINDOW(window),winWidth,winHeight);
	
	vbox = gtk_vbox_new(FALSE,0);
	gtk_container_add(GTK_CONTAINER(window),vbox);
	gtk_widget_show(vbox);
	
	// Application Menu
	fileMenu = gtk_menu_new();
	editMenu = gtk_menu_new();
	helpMenu = gtk_menu_new();
	
	newItem = gtk_image_menu_item_new_from_stock(GTK_STOCK_NEW, NULL);
	openItem = gtk_image_menu_item_new_from_stock(GTK_STOCK_OPEN, NULL);
	saveItem = gtk_image_menu_item_new_from_stock(GTK_STOCK_SAVE, NULL);
	saveAsItem = gtk_image_menu_item_new_from_stock(GTK_STOCK_SAVE_AS, NULL);
	exitItem = gtk_image_menu_item_new_from_stock(GTK_STOCK_QUIT, NULL);
	cutItem = gtk_image_menu_item_new_from_stock(GTK_STOCK_CUT, NULL);
	copyItem = gtk_image_menu_item_new_from_stock(GTK_STOCK_COPY, NULL);
	pasteItem = gtk_image_menu_item_new_from_stock(GTK_STOCK_PASTE, NULL);
	prefsItem = gtk_image_menu_item_new_from_stock(GTK_STOCK_PREFERENCES, NULL);
	runItem = gtk_image_menu_item_new_from_stock(GTK_STOCK_EXECUTE, NULL);
	cancelRunItem = gtk_image_menu_item_new_from_stock(GTK_STOCK_CANCEL, NULL);
	helpMeItem = gtk_image_menu_item_new_from_stock(GTK_STOCK_HELP, NULL);
	aboutItem = gtk_image_menu_item_new_from_stock(GTK_STOCK_ABOUT, NULL);
	
	gtk_menu_shell_append(GTK_MENU_SHELL(fileMenu),newItem);
	gtk_menu_shell_append(GTK_MENU_SHELL(fileMenu),openItem);
	gtk_menu_shell_append(GTK_MENU_SHELL(fileMenu),saveItem);
	gtk_menu_shell_append(GTK_MENU_SHELL(fileMenu),saveAsItem);
	gtk_menu_shell_append(GTK_MENU_SHELL(fileMenu),gtk_separator_menu_item_new());
	gtk_menu_shell_append(GTK_MENU_SHELL(fileMenu),exitItem);
	gtk_menu_shell_append(GTK_MENU_SHELL(editMenu),cutItem);
	gtk_menu_shell_append(GTK_MENU_SHELL(editMenu),copyItem);
	gtk_menu_shell_append(GTK_MENU_SHELL(editMenu),pasteItem);
	gtk_menu_shell_append(GTK_MENU_SHELL(editMenu),gtk_separator_menu_item_new());
	gtk_menu_shell_append(GTK_MENU_SHELL(editMenu),prefsItem);
	gtk_menu_shell_append(GTK_MENU_SHELL(editMenu),gtk_separator_menu_item_new());
	gtk_menu_shell_append(GTK_MENU_SHELL(editMenu),runItem);
	gtk_menu_shell_append(GTK_MENU_SHELL(editMenu),cancelRunItem);
	gtk_menu_shell_append(GTK_MENU_SHELL(helpMenu),helpMeItem);
	gtk_menu_shell_append(GTK_MENU_SHELL(helpMenu),aboutItem);
	
	fileItem = gtk_menu_item_new_with_mnemonic("_File");
	editItem = gtk_menu_item_new_with_mnemonic("E_dit");
	helpItem = gtk_menu_item_new_with_mnemonic("_Help");
	
	gtk_menu_item_set_submenu(GTK_MENU_ITEM(fileItem),fileMenu);
	gtk_menu_item_set_submenu(GTK_MENU_ITEM(editItem),editMenu);
	gtk_menu_item_set_submenu(GTK_MENU_ITEM(helpItem),helpMenu);
	
	gtk_widget_show(fileItem);
	gtk_widget_show(editItem);
	gtk_widget_show(helpItem);
	
	menuBar = gtk_menu_bar_new();
	
	gtk_menu_bar_append(GTK_MENU_BAR(menuBar),fileItem);
	gtk_menu_bar_append(GTK_MENU_BAR(menuBar),editItem);
	gtk_menu_bar_append(GTK_MENU_BAR(menuBar),helpItem);
	
	gtk_box_pack_start(GTK_BOX(vbox),menuBar,FALSE,FALSE,0);
	gtk_widget_show(menuBar);
	
	// Tool Bar
	toolBar = gtk_toolbar_new();
	gtk_container_set_border_width(GTK_CONTAINER(toolBar),2);
	
	tbNew = gtk_tool_button_new_from_stock(GTK_STOCK_NEW);
  gtk_toolbar_insert(GTK_TOOLBAR(toolBar), tbNew, -1);
  
  tbOpen = gtk_tool_button_new_from_stock(GTK_STOCK_OPEN);
  gtk_toolbar_insert(GTK_TOOLBAR(toolBar), tbOpen, -1);
  
  tbSave = gtk_tool_button_new_from_stock(GTK_STOCK_SAVE);
  gtk_toolbar_insert(GTK_TOOLBAR(toolBar), tbSave, -1);
  
  tbSaveAs = gtk_tool_button_new_from_stock(GTK_STOCK_SAVE_AS);
  gtk_toolbar_insert(GTK_TOOLBAR(toolBar), tbSaveAs, -1);
  
  gtk_toolbar_insert(GTK_TOOLBAR(toolBar), gtk_separator_tool_item_new(), -1);
  
  tbCut = gtk_tool_button_new_from_stock(GTK_STOCK_CUT);
  gtk_toolbar_insert(GTK_TOOLBAR(toolBar), tbCut, -1);
  
  tbCopy = gtk_tool_button_new_from_stock(GTK_STOCK_COPY);
  gtk_toolbar_insert(GTK_TOOLBAR(toolBar), tbCopy, -1);
  
  tbPaste = gtk_tool_button_new_from_stock(GTK_STOCK_PASTE);
  gtk_toolbar_insert(GTK_TOOLBAR(toolBar), tbPaste, -1);
  
  gtk_toolbar_insert(GTK_TOOLBAR(toolBar), gtk_separator_tool_item_new(), -1);
  
  tbPrefs = gtk_tool_button_new_from_stock(GTK_STOCK_PREFERENCES);
  gtk_toolbar_insert(GTK_TOOLBAR(toolBar), tbPrefs, -1);
  
  gtk_toolbar_insert(GTK_TOOLBAR(toolBar), gtk_separator_tool_item_new(), -1);
  
  tbRun = gtk_tool_button_new_from_stock(GTK_STOCK_EXECUTE);
  gtk_toolbar_insert(GTK_TOOLBAR(toolBar), tbRun, -1);
  
  tbCancelRun = gtk_tool_button_new_from_stock(GTK_STOCK_CANCEL);
  gtk_toolbar_insert(GTK_TOOLBAR(toolBar), tbCancelRun, -1);
  
  gtk_box_pack_start(GTK_BOX(vbox), toolBar, FALSE, FALSE, 0);
	
	// Query Window
	sqlEdit = gtk_text_view_new();
	scrollWindow = gtk_scrolled_window_new(NULL, NULL);
	gtk_scrolled_window_set_shadow_type(GTK_SCROLLED_WINDOW(scrollWindow), GTK_SHADOW_ETCHED_IN);
  gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(scrollWindow), GTK_POLICY_NEVER, GTK_POLICY_AUTOMATIC);
	
	gtk_container_add(GTK_CONTAINER(scrollWindow), sqlEdit);
	gtk_box_pack_start(GTK_BOX(vbox), scrollWindow, TRUE, TRUE, 0);
	
	sqlEditBuffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(sqlEdit));
	
	// Table Panel
	scrollGrid = gtk_scrolled_window_new(NULL, NULL);
	gtk_scrolled_window_set_shadow_type(GTK_SCROLLED_WINDOW(scrollGrid), GTK_SHADOW_ETCHED_IN);
  gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(scrollGrid), GTK_POLICY_NEVER, GTK_POLICY_AUTOMATIC);
  
  //store = gtk_list_store_new (NCOLS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);
  store = gtk_list_store_new (NCOLS, G_TYPE_STRING);
  for (i = 0; i < 9; i++) {
	  gtk_list_store_append(store, &iter);
	  gtk_list_store_set(store, &iter, DEFCOL, "      ", -1);
	}

	view = gtk_tree_view_new();
	gtk_tree_view_set_rules_hint(GTK_TREE_VIEW(view), TRUE);
  gtk_tree_view_set_search_column(GTK_TREE_VIEW(view), DEFCOL);
	
	renderer = gtk_cell_renderer_text_new();
  gtk_tree_view_insert_column_with_attributes(GTK_TREE_VIEW(view), -1, "      ", renderer, "text", DEFCOL, NULL);
  /*column = gtk_tree_view_column_new_with_attributes("Name", renderer, "text", NAME, NULL);
  gtk_tree_view_column_set_sort_column_id(column, NAME);
  gtk_tree_view_append_column(GTK_TREE_VIEW(view), column);*/
  
  model = GTK_TREE_MODEL(store);
  
  gtk_tree_view_set_model(GTK_TREE_VIEW(view), model);
  g_object_unref(model);
  
  gtk_container_add(GTK_CONTAINER(scrollGrid), view);
  gtk_box_pack_start(GTK_BOX(vbox), scrollGrid, TRUE, TRUE, 0);
	
	// Display All Widgets
	gtk_widget_show_all(window);
}

#endif

