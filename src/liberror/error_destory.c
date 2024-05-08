void	error_destory(void *self)
{
	ft_bzero(self, sizeof(t_error));
	free(self);
}
