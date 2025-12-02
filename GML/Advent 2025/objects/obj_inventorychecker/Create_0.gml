function day_two_part_one()
{
	var buff = buffer_load("gift_data.txt");
	var data = buffer_read(buff, buffer_string);
	buffer_delete(buff);
	
	var file_reader_index = 0;
	
	var invalid_sum = int64(0);
	var invalid_ids = [];
	
	var lower_bound_found = false;
	var lower_bound = int64(0);
	var higher_bound = int64(0);
	
	while(file_reader_index <= string_length(data))
	{
		file_reader_index++;
		
		var curr_id_string = "";
		
		if(string_char_at(data, file_reader_index) == "-")
		{
			lower_bound_found = true;
		}
		else if(string_digits(string_char_at(data, file_reader_index)) != "" && string_digits(string_char_at(data, file_reader_index)) < 10 && string_digits(string_char_at(data, file_reader_index)) > -1)
		{
			if(!lower_bound_found)
			{
				lower_bound *= int64(10);
				lower_bound += int64(string_digits(string_char_at(data, file_reader_index)));
			}
			else
			{
				higher_bound *= int64(10);
				higher_bound += int64(string_digits(string_char_at(data, file_reader_index)));
			}
		}
		else
		{
			for(var barcode = int64(lower_bound); barcode <= int64(higher_bound); barcode += int64(1))
			{
				curr_id_string = string(barcode);
				if(string_length(curr_id_string) % 2 == 1)
				{
					continue;
				}
				
				var valid_id = false;
				
				for(var i = 1; i < string_length(curr_id_string) / 2 + 1; i++)
				{
					if(string_char_at(curr_id_string, i) != string_char_at(curr_id_string, string_length(curr_id_string) / 2 + i))
					{
						valid_id = true;
						break;
					}
				}
				
				if(valid_id) continue;
				
				invalid_sum += int64(string_digits(curr_id_string));
			}
			
			lower_bound_found = false;
			lower_bound = int64(0);
			higher_bound = int64(0);
		}
	}
	
	show_debug_message(invalid_sum);
}

function day_two_part_two()
{
	var buff = buffer_load("gift_data.txt");
	var data = buffer_read(buff, buffer_string);
	buffer_delete(buff);
	
	var file_reader_index = 0;
	
	var invalid_sum = int64(0);
	var invalid_ids = [];
	
	var lower_bound_found = false;
	var lower_bound = int64(0);
	var higher_bound = int64(0);
	
	while(file_reader_index <= string_length(data))
	{
		file_reader_index++;
		
		var curr_id_string = "";
		
		if(string_char_at(data, file_reader_index) == "-")
		{
			lower_bound_found = true;
		}
		else if(string_digits(string_char_at(data, file_reader_index)) != "" && string_digits(string_char_at(data, file_reader_index)) < 10 && string_digits(string_char_at(data, file_reader_index)) > -1)
		{
			if(!lower_bound_found)
			{
				lower_bound *= int64(10);
				lower_bound += int64(string_digits(string_char_at(data, file_reader_index)));
			}
			else
			{
				higher_bound *= int64(10);
				higher_bound += int64(string_digits(string_char_at(data, file_reader_index)));
			}
		}
		else
		{
			var invalide_ids = [];
			
			for(var barcode = int64(lower_bound); barcode <= int64(higher_bound); barcode += int64(1))
			{
				curr_id_string = string(barcode);
				
				for(var rep_len = 1; rep_len <= string_length(curr_id_string) / 2; rep_len++)
				{
					if(string_length(curr_id_string) % rep_len != 0)
					{
						continue;
					}
				
					var valid_id = false;
					
					for(var i = 1; i < string_length(curr_id_string) / rep_len; i++)
					{
						for(var j = 1; j <= rep_len; j++)
						{
							if(string_char_at(curr_id_string, j) != string_char_at(curr_id_string, i * rep_len + j))
							{
								valid_id = true;
								break;
							}
						}
						
						if(valid_id)
						{
							break;
						}
					}
				
					if(valid_id) continue;
					
					if(!array_contains(invalid_ids, int64(string_digits(curr_id_string))))
					{
						invalid_sum += int64(string_digits(curr_id_string));
						array_push(invalid_ids, int64(string_digits(curr_id_string)));
					}
				}
			}
			
			lower_bound_found = false;
			lower_bound = int64(0);
			higher_bound = int64(0);
		}
	}
	
	show_debug_message(invalid_sum);
}

day_two_part_one();

day_two_part_two();