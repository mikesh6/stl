/********************************************
* Titre: Travail pratique #5 - Foncteur.h
* Date: 9 mars 2018
* Auteur: Ryan Hardie
*******************************************/

#pragma once

#include <algorithm>  
#include <set>
#include <map>
#include "Usager.h"
using namespace std;


// TODO : Cr�er le FoncteurEgal
template<typename T>
class FoncteurEgal {

public:
	FoncteurEgal(T* t)

		{t_ = t}
	bool operator()(pair<int, T*> nom) {
		if (nom.second == t_) {
			return true;

		}
		else
			return false;
	}
private:
	T* t_;
};




// TODO : Cr�er le FoncteurGenerateurId
/*
Attributs :
- id_;
M�thodes :
- operator(); Incr�menter id_ � chaque appel
*/

class FoncteurGenerateurId {

public:
	FoncteurGenerateurId() {
		id_ = 0;
	}

	int operator()() {
		return id_++;
	}
	
private:
	int id_;
};



// TODO : Cr�er le FoncteurDiminuerPourcent
/*
Attributs :
- pourcentage_;
M�thodes :
- operator(); Calule le nouveau prix du Produit de la pair pass� en param�tre et le modifie
*/
class FoncteurDiminuerPourcent {

public:

	double price = 0.0;
	double percentage = 0.0;
	FoncteurDiminuerPourcent(int pourcentage) {
		int pourcentage_ = pourcentage;
	}
	// nouveau prix = prix du produit - (prix du produit*pourcentage)
	void operator()(pair<int, Produit*> pairPourcent) {

		price = pairPourcent.second->obtenirPrix();
		pairPourcent.second->modifierPrix( price =  price - (price*pourcentage_));
	}

private:
	int pourcentage_;
};


// TODO : Cr�er le FoncteurIntervalle
/*
Attributs :
- borneInf_;
- borneSup_;
M�thodes :
- operator(); V�rifie que le Produit associ� � la pair pass� en param�tre est compris entre les bornes borneInf_ et borneSup_ (retourne un bool�en)
*/
class FoncteurIntervalle {

public:
	FoncteurIntervalle(double borneInf, double borneSup) {
		borneInf_ = borneInf;
		borneSup_ = borneSup;
	}
	// nouveau prix = prix du produit - (prix du produit*pourcentage)
	bool operator()(pair<int, Produit*> pairIntervalle) {
		if (pairIntervalle.second->obtenirPrix() > borneInf_ && pairIntervalle.second->obtenirPrix() < borneSup_) {
			return true;

		}
		else
			return false;
	}

private:
	double borneInf_;
	double borneSup_;
};

// TODO : Cr�er le Foncteur AjouterProduit
/*
Attributs :
- &multimap_;
M�thodes :
- operator(); Ajoute dans la multimap la pair pass� par param�tre et retourne la multimap_;
*/
class FoncteurAjouterProduit {

public:
	FoncteurAjouterProduit(multimap<int, Produit*>& mapProduit) : multimap_(mapProduit) {
	};
	
	multimap<int, Produit*>& operator()(Produit* p) {

		multimap_.insert(std::make_pair(p->obtenirReference(), p));
		return multimap_;

	};


private:
	multimap<int,Produit*> &multimap_ ;

};


// TODO : Cr�er le Foncteur SupprimerProduit
/*
Attributs :
- &multimap_;
M�thodes :
- operator(); Utilise la fonction find_if avec le FoncteurEgal. Si le Produit existe,
				on supprime le Produit et on retourne la multimap_,
				sinon on retourne juste la multimap_ sans supprimer l'�l�ment.
*/


class FoncteurSupprimerProduit {

public:
	FoncteurSupprimerProduit(multimap<int, Produit*>& mapProduit) : multimap_(mapProduit) {};
	template <class FoncteurEgal, class InputIterator>
	multimap<int, Produit*>& operator()(Produit* p) {

		//iterateur pointe vers l'objet trouv� que l'on souhaite supprimer
		InputIterator produitASupprimer = find_if(multimap_.begin(), multimap_.end(), FoncteurEgal(p));

		//verifier if produitASupprimer = nullptr (si le produit est parmi la liste donc s'il existe)
		multimap_.erase(produitASupprimer);
		return multimap_;

	};


private:
	multimap<int, Produit*> &multimap_;

};

//TODO : Cr�er le Foncteur AjouterUsager
/*
Attributs :
- &set;
M�thodes :
- operateur(); Trouve l'Usager dans le set_, s'il existe on le supprime et on retourne le set_, sinon on retourne juste directement le set_.
*/
class FoncteurAjouterUsager {

public:
	FoncteurAjouterUsager(set<Usager*>& setUsager) : set_(setUsager) {};

	void operator()(Usager* usager) {

		set_.insert(usager);
		

	};


private:
	set<Usager*> &set_;

};


class FoncteurSupprimerUsager {

public:
	FoncteurSupprimerUsager(set<Usager*> setUsager) : set_(setUsager) {
	};

	set<Usager*>& operator()(Usager* usager) {

		set_.erase(usager);//not sure this would work, do we need an iterator here ?
	};


private:
	set<Usager*> &set_;

};
