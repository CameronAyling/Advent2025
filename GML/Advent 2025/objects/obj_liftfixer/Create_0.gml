function day_three_part_one()
{
	var buff = buffer_load("lift_data.txt");
	var data = buffer_read(buff, buffer_string);
	buffer_delete(buff);
	
	var file_reader_index = -1;
	var line = "";
	
	var joltage_sum = int64(0);
	
	var num_of_digits = 12;
	
	while(file_reader_index <= string_length(data))
	{
		file_reader_index++;
		
		if(string_char_at(data, file_reader_index) == "\n" || file_reader_index == string_length(data) + 1)
		{
			var curr_jolt = int64(0);
			var highest_jolt = 0;
			var highest_jolt_index = 0;
			
			for(var digits = 0; digits < num_of_digits; digits++)
			{
				highest_jolt = 0;
				
				for(var i = highest_jolt_index + 1; i < string_length(line) - (num_of_digits - 1 - digits); i++)
				{
					if(string_digits(string_char_at(line, i)) > highest_jolt)
					{
						highest_jolt = string_digits(string_char_at(line, i));
						highest_jolt_index = i;
					}
				}
				
				curr_jolt *= 10;
				curr_jolt += highest_jolt;
			}
			
			show_debug_message(curr_jolt);
			
			joltage_sum += int64(curr_jolt);
			
			line = "";
		}
		else
		{
			line = string_concat(line, string_char_at(data, file_reader_index));
		}
	}
	
	show_debug_message(joltage_sum);
}

day_three_part_one();