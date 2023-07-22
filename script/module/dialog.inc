DialogCreate:attach_main(playerid) {
	Dialog_Open(
		playerid,
		Dialog:attach_main,
		DIALOG_STYLE_INPUT,
		"Создание нового аксессуара - редактирование",
		"{FFFFFF}Введите ID Объекта, индекс и кость через запятую.",
		"Ввод", "Закрыть"
	);
	return true;
}

DialogResponse:attach_main(playerid, response, listitem, inputtext[]) {
	new
		object_id,
		object_index,
		object_bone;
	
	if(sscanf(inputtext, "p<,>iii", object_id, object_index, object_bone)) {
		SendClientMessage(playerid, 0xAFAFAFFF, "Вы ввели не все параметры.");
		Dialog_Show(playerid, Dialog:attach_main);
		return true;
	}

	SetPlayerSkin(playerid, 1);

	SetPlayerAttachedObject(
		playerid,
		object_index,
		object_id,
		object_bone
	);

	EditAttachedObject(playerid, object_index);

	attach_info[playerid][current_skin] = 1;
	attach_info[playerid][attach_object] = object_id;
	attach_info[playerid][attach_index] = object_index;
	attach_info[playerid][attach_bone] = object_bone;
	attach_info[playerid][attach_status] = true;

	SendClientMessage(playerid, -1, "Нажмите 'Сохранить' чтобы перейти к следующему скину.");
	new
		day,
		month,
		year,
		hour,
		minute,
		second,
		player_name[MAX_PLAYER_NAME];

	GetPlayerName(playerid, player_name, sizeof(player_name));
	gettime(hour, minute, second);
	getdate(year, month, day);

	format(string_text, sizeof(string_text), "%s-objid-%i.ini",
	player_name, object_id);

	format(string_small, sizeof(string_small), "[ OBJECT ID: %i | BONE: %i ]", object_id, object_bone);

	new iniFile = ini_createFile ( string_text , string_small);

	if ( iniFile < 0 ) {
		iniFile = ini_openFile ( string_text );
	} else {

		ini_setString  ( iniFile, "| SKINID | X | Y | Z | RX | RY | RZ |", "test_ammount" );

		ini_closeFile  ( iniFile );

	}
	
	return true;
}