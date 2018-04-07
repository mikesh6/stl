/********************************************
* Titre: Travail pratique #5 - GestionnaireGenerique.h
* Date: 9 mars 2018
* Auteur: Ryan Hardie
*******************************************/


#pragma once

#include <algorithm>




template<typename T, typename A, typename C, typename S>
class GestionnaireGenerique {
public:

	

	void ajouter(T*t) {

		A add(conteneur_);
		add(t);
		//funcAdd(t)


	};
	//void supprimer(T*t) {
	//
		//S del(conteneur_);
		//del(t);
	//
	//};

	C obtenirConteneur() const {
		return conteneur_;
	};

	template<typename Predicat>
	void pourChaqueElement(Predicat predicat) {
		for_each(conteneur_.begin(), conteneur_.end(), predicat);
	};


protected:


	C conteneur_;

};