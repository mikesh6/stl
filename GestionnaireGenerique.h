/********************************************
* Titre: Travail pratique #5 - GestionnaireGenerique.h
* Date: 9 mars 2018
* Auteur: Ryan Hardie
*******************************************/

#include "Gestionnaire.h"
#pragma once

template<typename T, typename A, typename C, typename S>

class GestionnaireGenerique {

public:
	A ajoute();
	S supprime();
	Predicate pourChaqueElement();

private:

protected:
	 Gestionnaire* conteneur_;



};
// TODO : Créer la classe GestionnaireGenerique

// TODO : Méthodes :
/*
- ajouter()
- supprime()
- obtenirConteneur()
- pourChaqueElement() //for_each
*/

template<typename T, typename A, typename C, typename S>
inline A GestionnaireGenerique<T, A, C, S>::ajoute()
{
	return A();
}
