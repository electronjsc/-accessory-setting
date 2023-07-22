enum edit_attach {
	current_skin,
	attach_object,
	attach_index,
	attach_bone,
	bool:attach_status,
}

new attach_info[MAX_PLAYERS][edit_attach];

new string_text[256], string_small[144];