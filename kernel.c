void kmain(void)
{
	const char *str = "my first kernel";
	char *vidptr = (char*)0xb8000; 	//video mem begins here.
	unsigned int i = 0;
	unsigned int j = 0;

	// Clear screen
	while(j < 80 * 25 * 2)
	{
		/* blank character */
		vidptr[j] = ' ';
		/* attribute-byte - light grey on black screen */
		vidptr[j+1] = 0x07; 		
		j = j + 2;
	}

	j = 0;

	// Write to video memory
	while(str[j] != '\0')
	{
		/* the character's ascii */
		vidptr[i] = str[j];
		/* attribute-byte: give character black bg and light grey fg */
		vidptr[i+1] = 0x07;
		++j;
		i = i + 2;
	}
	return;
}