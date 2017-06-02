#ifndef PARSER_H
# define PARSER_H

# define INVALID_SIZE_NBR "Error : Invalid number, number must be less than 17 digit"
# define INVALID_DECIMAL "Warning : RT_v1 doesn't not support precison more than 4 digit"
# define INVALID_FORMA_NBR "Error : Invalid number, number bad formated"
# define INVALID_PARAM "Error : Invalid parametre, some character in the parameter are not valid"
# define INVALID_NBR_OF_PARAM "Error : Invalid number of parameters, this argument needs only 3 parameters"
# define INVALID_PARAM_FORMAT "Error : Invalid formatage of parameter"
# define INVALID_HEXA_FORMAT "Error : Hexa numbers must start with 0x. Minuscule and majuscules for letters are allowed."
# define INVALID_PARAMS "Error : Invalid parametres"
# define INVALID_HEXA_SIZE "Error : hexa number must be less than 8 digits"
# define INVALID_EXTENTION "Error : Invalid extention file [scene].rt"
# define INVALID_FORMAT_CHEVRON "Error : Invalid format : missing a chevron after declaring an object"
# define INVALID_DESCRIPTION "Error : Invalid description of an object, check the manual"
# define INVALID_FORMAT_FILE "Error : Invalid file format"
# define USAGE "Usage : ./rtv1 no source or one source"
# define BAD_INDENT "Error : Bad indentation"
# define INVALID_OBJECT "Error : There is more than one valid caracteristic precised"
# define INVALID_INT "Error : Invalid int"
# define INVALID_NORMAL "Error : normale of a plan cannot be null"
# define INVALID_CAMERA "Error : camera cannot watch itself"
# define BAD_COEFF "Error : coeffs like specular or diffuse must be between 0 and 1"
# define INVALID_LIGHT "Error : light speuclarity + light diffuse cannot be greater than one"
# define INVALID_ANGLE "Error : angle must be lower than 180 degrees"
# define INVALID_FILE "Error : the file is not valid"
# define INVALID_DIRECTORY "Error : argument is a directory"
# define INVALID_NO_OBJ "Error : List object null"
# define INVALID_LOOKAT "Error : camera matrix LookAt error because the camera is looking straight up or down to (0 1 0) and the matrix is not defined"

# define POSITION "position:"
# define RAYON "rayon:"
# define COLOR "color:"
# define NORMAL "normal:"
# define TO "to:"
# define FROM "from:"
# define APEX "apex:"
# define AXIS "axis:"
# define BRILLANCE "brillance:"
# define ANGLE "angle:"
# define ROTATION "rotation:"
# define INTENSITY "intensity:"
# define SIZE "size:"
# define SPECULAR "specular:"
# define DIFFUSE "diffuse:"


int		check_indent(char *str, int n);
int		parse_error(char *str);
int 	fill_data(char *tmp, double *data);
int		check_floating_number(char *str);
int		fill_data_vec(char *str, t_vector *vec);
int		check_data_type_color(char *str);
int		check_data_type_nbr(char *str, int k);
int		error_file(char *file);
int		fill_int_data(char *str, int *data);

typedef struct s_pars_object
{
	int		to;
	int		from;
	int		position;
	int		brillance;
	int		angle;
	int		rayon;
	int		color;
	int		apex;
	int		axis;
	int		normal;
	int		rotation;
	int		intensity;
	int		size;
	int		diffuse;
	int		specular;
}				t_pars_object;

#endif
