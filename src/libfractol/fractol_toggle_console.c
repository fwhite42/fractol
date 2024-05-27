/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   fractol_toggle_console.c                                4 2              */
/*                                                        (@)-=-(@)           */
/*   By: fwhite42 <FUCK THE NORM>                          (  o  )            */
/*                                                       _/'-----'\_          */
/*   Created: 2024/05/27 01:46:53 by fwhite42          \\ \\     // //        */
/*   Updated: 2024/05/27 02:02:25 by fwhite42           _)/_\---/_\(_         */
/*                                                                            */
/* ************************************************************************** */

int	fractol_toggle_console(t_fractol *self)
{
	if (cmd == KEY_SPACE_BAR)
	{
		this->draw_console_switch = !this->draw_console_switch;
		if (!this->draw_console_switch)
			screen_refresh_old(this->screen, this->mlx);
		else
			fractol_show_console(self);
		return (1);
	}
	return (0);
}
