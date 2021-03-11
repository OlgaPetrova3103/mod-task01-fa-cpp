unsigned int faStr1(const char *str)
{
    int i = 0,
		count = 0,
		in = 0,//0-вне слова
		F = 0; //0-обнаружилась цифра
	while (str[i] != '\0')
	{
		if (in == 0 && str[i] != ' ')
		{
			if (str[i] > 57 || str[i] < 48) F = 1;
			in = 1;
		}
		else if (in == 1 && str[i] != ' ' && F == 1)
		{
			if (str[i] >= 48 && str[i] <= 57) F = 0;
		}
		else if (in == 1 && str[i] == ' ') 
		{
			if (F == 1) count++;
			F = 0;
			in = 0;
		}

		i++;
	}
	if (in == 1 && F == 1) count++;
	return count;
}



unsigned int faStr2(const char *str)
{
    int i = 0, count = 0,
		in = 0,
		F = 0;
	while (str[i] != '\0')
	{
		if (in == 0 && str[i] >= 65 && str[i] <= 90)
		{
			in = 1;
			F = 1;
		}
		else if (in == 1 && str[i] != ' ' && F == 1)
		{
			if (str[i] >= 65 && str[i] <= 90) F = 0;
			if (str[i] > 122 || str[i] < 65) F = 0;
		}
		else if (in == 1 && str[i] == ' ')
		{
			if (F == 1) count++;
			F = 0;
			in = 0;
		}

		i++;
	}
	if (in == 1 && F == 1) count++;
	return count;
}




unsigned int faStr3(const char *str)
{
    int i = 0, count = 0,
		in = 0,
		leng = 0,
		answer;
	float sum = 0;
	while (str[i] != '\0')
	{
		if (in == 0 && str[i] != ' ')
		{
			count++;
			in = 1;
			leng++;
		}
		else if (in == 1 && str[i] != ' ') leng++;
		else if (in == 1 && str[i] == ' ')
		{
			sum = sum + leng;
			in = 0;
			leng = 0;
		}
		i++;
	}
	if (in == 1) sum = sum + leng;
	sum = sum / (float)count;
	answer = sum;
	if (sum - (float)answer >= 0.5) answer++;
	return answer;
}
