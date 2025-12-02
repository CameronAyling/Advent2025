function day_one_part_one()
{
	var buff = buffer_load("safe_data.txt");
	var data = buffer_read(buff, buffer_string);
	buffer_delete(buff);
	
	var file_reader_index = -1;
	var line = "";
	
	var position = 50;
	var zeroes = 0;
	
	while(file_reader_index <= string_length(data))
	{
		file_reader_index++;
		
		if(string_char_at(data, file_reader_index) == "\n" || file_reader_index == string_length(data) + 1)
		{
			///////////////////////////
			// PROCESS THE LINE HERE //
			///////////////////////////
			var line_length = string_length(line);
			
			var to_add = 0;
			
			switch(string_char_at(line, 0))
			{
				case "L":
					to_add -= string_digits(line);
					break;
				case "R":
					to_add += string_digits(line);
					break;
			}
			
			position += to_add;
			
			while(position < 0)
			{
				position += 100;
			}
			
			while(position > 99)
			{
				position -= 100;
			}
			
			if(position == 0)
			{
				zeroes++;
			}
			
			// RESET THE LINE
			line = "";
		}
		else
		{
			line = string_concat(line, string_char_at(data, file_reader_index));
		}
	}
	
	show_debug_message(zeroes);
}

function day_one_part_two()
{
	var buff = buffer_load("safe_data.txt");
	var data = buffer_read(buff, buffer_string);
	buffer_delete(buff);
	
	var file_reader_index = 0;
	var line = "";
	
	var position = 50;
	var zeroes = 0;
	
	while(file_reader_index <= string_length(data))
	{
		file_reader_index++;
		
		if(string_char_at(data, file_reader_index) == "\n" || file_reader_index == string_length(data) + 1)
		{
			///////////////////////////
			// PROCESS THE LINE HERE //
			///////////////////////////
			
			var line_length = string_length(line);
			
			var is_left = string_char_at(line, 1) == "L";
			
			zeroes -= (position == 0) && is_left;
			
			for(var i = 2; i < line_length; i++)
			{
				if(line_length - i < 3)
				{
					position += real(string_char_at(line, i)) * power(10, line_length - i - 1) * (is_left ? -1 : 1);
				}
				else
				{
					zeroes += real(string_char_at(line, i)) * power(10, line_length - i - 3);
				}
			}
			
			if(position < 0)
			{
				position += 100;
				zeroes++;
			}
			else if(position > 99)
			{
				position -= 100;
				zeroes++;
			}
			else if(position == 0)
			{
				zeroes++;
			}
			
			// RESET THE LINE
			line = "";
		}
		else
		{
			line = string_concat(line, string_char_at(data, file_reader_index));
		}
	}
	
	show_debug_message(zeroes);
}

day_one_part_one();
day_one_part_two();