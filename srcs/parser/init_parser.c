#include "../include/rtv1.h"

/*
 * 	{							{
 * 		0 --> "sphere"				0 --> set_sphere
 * 		1 --> "cone"				1 --> set_cone
 * 		2 --> "cylinder"			2 --> set_cylinder
 * 		3 --> "plan"				3 --> set_plan
 * 		...							...
 * 	}							{
 */

void	init_tab_str_description(t_env *env)
{
	if (!(env->tab_str_description = (
					char**)malloc(sizeof(char*) * NBR_DESCRIPTION)))
		merror();
	env->tab_str_description[0] = ft_strdup(POSITION);
	env->tab_str_description[1] = ft_strdup(RAYON);
	env->tab_str_description[2] = ft_strdup(COLOR);
	env->tab_str_description[3] = ft_strdup(NORMAL);
	env->tab_str_description[4] = ft_strdup(APEX);
	env->tab_str_description[5] = ft_strdup(AXIS);
	env->tab_str_description[6] = ft_strdup(BRILLANCE);
	env->tab_str_description[7] = ft_strdup(ANGLE);
	env->tab_str_description[8] = ft_strdup(ROTATION);
	env->tab_str_description[9] = ft_strdup(SIZE);
	env->tab_str_description[10] = ft_strdup(DIFFUSE);
	env->tab_str_description[11] = ft_strdup(SPECULAR);
}

void	init_tab_function_description(t_env *env)
{
	env->check_description[0] = &set_position;
	env->check_description[1] = &set_rayon;
	env->check_description[2] = &set_color;
	env->check_description[3] = &set_normal;
	env->check_description[4] = &set_apex;
	env->check_description[5] = &set_axis;
	env->check_description[6] = &set_brillance;
	env->check_description[7] = &set_angle;
	env->check_description[8] = &set_rotation;
	env->check_description[9] = &set_size;
	env->check_description[10] = &set_diffuse;
	env->check_description[11] = &set_specular;
}

void	init_tab_str_object(t_env *env)
{
	if (!(env->tab_str_object = (char**)malloc(sizeof(char*) * NBR_OBJECT)))
		merror();
	env->tab_str_object[SPHERE] = ft_strdup("sphere:");
	env->tab_str_object[CONE] = ft_strdup("cone:");
	env->tab_str_object[CYLINDRE] = ft_strdup("cylinder:");
	env->tab_str_object[PLAN] = ft_strdup("plan:");
	env->tab_str_object[CAMERA] = ft_strdup("camera:");
	env->tab_str_object[LIGHT] = ft_strdup("light:");
}

void	init_tab_function_object(t_env *env)
{
	env->set_object[SPHERE] = &set_sphere;
	env->set_object[CONE] = &set_cone;
	env->set_object[CYLINDRE] = &set_cylinder;
	env->set_object[PLAN] = &set_plan;
	env->set_object[CAMERA] = &set_camera;
	env->set_object[LIGHT] = &set_light;
}
