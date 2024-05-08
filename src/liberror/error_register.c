void error_register(void *self, int value, char* message)
{
	if (self)
	{
		((t_error *)self)->value ^= value;
		((t_error *)self)->message = message;
	}
}
