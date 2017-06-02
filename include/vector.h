#ifndef VECTOR_H
# define VECTOR_H

#include <math.h>
#include <stdlib.h>

typedef struct	s_vector
{
	double	x;
	double	y;
	double	z;
	double	norme;
}				t_vector;

// croos product - produit vectoriel
t_vector	cross_product(t_vector a, t_vector b);
// produit scalaire - retourne un int
double		dot_product(t_vector a, t_vector b);
// cree un vecteur a partir de lorigine et dun autre point represente par 3 int
void		set_vec(t_vector *v, double x, double y, double z);
// normalize un vecetur
void		normalize_vec(t_vector *vector);
// difference de deux vecteur a - b
t_vector	vec_diff(t_vector a, t_vector b);
// multiplie tous les coeefs dun vecteur par un int
t_vector	n_vec(t_vector v, double n);
t_vector	vec_add(t_vector a, t_vector b);
void		negative_vec(t_vector *v);

t_vector	product_vec_matrix(double *m, t_vector v);
t_vector		product_matrix4x4(double *m, t_vector v);

# endif
