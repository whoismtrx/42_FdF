/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_to_win.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orekabe <orekabe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 03:42:23 by orekabe           #+#    #+#             */
/*   Updated: 2022/07/03 04:25:13 by orekabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_put_str_to_win(t_win *win)
{
	mlx_string_put(win->mlx, win->mlx_win, 10, WIN_H - 540, 0x00ff00ff,
		"PROJECTION :");
	mlx_string_put(win->mlx, win->mlx_win, 10, WIN_H - 520, 0x00ffffff,
		"PARALLEL = P");
	mlx_string_put(win->mlx, win->mlx_win, 10, WIN_H - 500, 0x00ffffff,
		"ISOMETRIC = I");
	mlx_string_put(win->mlx, win->mlx_win, 10, WIN_H - 480, 0x00ff00ff,
		"ZOOM :");
	mlx_string_put(win->mlx, win->mlx_win, 10, WIN_H - 460, 0x00ffffff,
		"ZOOM IN = SCROLL UP");
	mlx_string_put(win->mlx, win->mlx_win, 10, WIN_H - 440, 0x00ffffff,
		"ZOOM OUT = SCROLL DOWN");
	mlx_string_put(win->mlx, win->mlx_win, 10, WIN_H - 420, 0x00ff00ff,
		"TRANSLATE :");
	mlx_string_put(win->mlx, win->mlx_win, 10, WIN_H - 400, 0x00ffffff,
		"MOVE UP = W");
	mlx_string_put(win->mlx, win->mlx_win, 10, WIN_H - 380, 0x00ffffff,
		"MOVE DOWN = S");
	mlx_string_put(win->mlx, win->mlx_win, 10, WIN_H - 360, 0x00ffffff,
		"MOVE LEFT = A");
	mlx_string_put(win->mlx, win->mlx_win, 10, WIN_H - 340, 0x00ffffff,
		"MOVE RIGHT = D");
	mlx_string_put(win->mlx, win->mlx_win, 10, WIN_H - 320, 0x00ff00ff,
		"ROTATOIN :");
	mlx_string_put(win->mlx, win->mlx_win, 10, WIN_H - 300, 0x00ffffff,
		"X AXE UP = ARROW UP");
	mlx_string_put(win->mlx, win->mlx_win, 10, WIN_H - 280, 0x00ffffff,
		"X AXE DOWN = ARROW DOWN");
	mlx_string_put(win->mlx, win->mlx_win, 10, WIN_H - 260, 0x00ffffff,
		"Y AXE LEFT = ARROW LEFT");
	mlx_string_put(win->mlx, win->mlx_win, 10, WIN_H - 240, 0x00ffffff,
		"Y AXE RIGHT = ARROW RIGHT");
	mlx_string_put(win->mlx, win->mlx_win, 10, WIN_H - 220, 0x00ffffff,
		"Z AXE CLOCKWISE = PAGE DOWN");
	mlx_string_put(win->mlx, win->mlx_win, 10, WIN_H - 200, 0x00ffffff,
		"Z AXE COUNTERCLOCKWISE = PAGE UP");
	mlx_string_put(win->mlx, win->mlx_win, 10, WIN_H - 180, 0x00ffff00,
		"<EXTRA FEATURES>");
	mlx_string_put(win->mlx, win->mlx_win, 10, WIN_H - 160, 0x00ff00ff,
		"CONTROL ALTITUDE :");
	mlx_string_put(win->mlx, win->mlx_win, 10, WIN_H - 140, 0x00ffffff,
		"MOVE UP = +");
	mlx_string_put(win->mlx, win->mlx_win, 10, WIN_H - 120, 0x00ffffff,
		"MOVE DOWN = -");
	mlx_string_put(win->mlx, win->mlx_win, 10, WIN_H - 100, 0x00ff00ff,
		"COLORS :");
	mlx_string_put(win->mlx, win->mlx_win, 10, WIN_H - 80, 0x00ffffff,
		"CHANGE COLORS = C");
	mlx_string_put(win->mlx, win->mlx_win, 10, WIN_H - 60, 0x00ff00ff,
		"RESET :");
	mlx_string_put(win->mlx, win->mlx_win, 10, WIN_H - 40, 0x00ffffff,
		"RESET TO DEFAULT = R");
}