#include "../include/rtv1.h"

void	sort_camera(t_env *env)
{
	t_camera	*cam;
	t_list		*tmp_cam;
	int			i;

	i = 0;
	tmp_cam = env->camera;
	cam = (t_camera*)(tmp_cam->content);
	cam->num = 0;
	env->select->c = cam;
	tmp_cam = tmp_cam->next;
	while (tmp_cam)
	{
		cam = (t_camera*)(tmp_cam->content);
		cam->num = ++i;
		tmp_cam = tmp_cam->next;
	}
	env->nbr_cam = cam->num;
}
