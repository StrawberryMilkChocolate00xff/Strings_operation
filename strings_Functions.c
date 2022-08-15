unsigned int strings_length(char *t)
{
	unsigned int n = 0;

	while (!(t[n] == (unsigned char)0))
	{
		++n;
	}

	return n + 1;
}

unsigned char strings_copy(char *t, char *s, unsigned int n)
{
	unsigned int length_target, length_source;
	length_target = strings_length(t);
	length_source = strings_length(s);

	if (length_source > length_target)
	{
		unsigned int i = 0;
		for (i; i < n; ++i)
		{
			t[i] = s[i];
		}
	}

	if (length_source <= length_target)
	{
		unsigned int i = 0;
		for (i; i < length_source - 1; ++i)
		{
			t[i] = s[i];
		}
	}

	return 0xFF;
}

unsigned char strings_compare(char *t, char *s)
{
	unsigned int length_target, length_source;
	length_target = strings_length(t);
	length_source = strings_length(s);

	if (length_target == length_source)
	{
		unsigned int number = 0, number_strings = 0;
		while (number < length_target && number < length_source)
		{
			if (t[number] == s[number])
			{
				++number_strings;
			}
			++number;
		}

		if (number_strings == length_target && number_strings == length_source)
		{
			return 0xFF;
		}
		else
		{
			return 0x01;
		}
	}
	
	return 0x00;
}

unsigned char strings_partCopy(char *t, char *s, unsigned int n, unsigned int offset)
{
	unsigned int length_target, length_source;
	length_target = strings_length(t);
	length_source = strings_length(s);

	if (length_source > length_target)
	{
		return 0x00;
	}

	if (n + offset > length_target - 1)
	{
		return 0x01;
	}

	if (n > length_source - 1)
	{
		return 0x02;
	}

	{
		unsigned int address_target = offset, number = 0;
		for (number; number < n; ++number)
		{
			t[address_target] = s[number];
			++address_target;
		}
		return 0xFF;
	}
}
