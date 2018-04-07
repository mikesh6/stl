/********************************************
* Titre: Travail pratique #5 - GestionnaireProduits.h
* Date: 9 mars 2018
* Auteur: Ryan Hardie
*******************************************/
#ifndef GESTIONNAIREPRODUITS_H
#define GESTIONNAIREPRODUITS_H
#pragma once

#include "GestionnaireGenerique.h"
#include "Produit.h"
#include "Foncteur.h"
#include <map>
#include <functional> //for the bind stl

class GestionnaireProduits : public GestionnaireGenerique <Produit, FoncteurAjouterProduit, multimap<int, Produit*>, FoncteurSupprimerProduit> {

public:


	GestionnaireProduits();
	~GestionnaireProduits();


	void reinitialiserClient(); 
	void reinitialiserFournisseur();
	void afficher() const;
	double obtenirTotalAPayer();
	double obtenirTotalApayerPremium();
    //Produit* trouverProduitPlusCher();
	//vector<pair<int, Produit*>> obtenirProduitsEntre(double lowerR, double upperR);
	//Produit* obtenirProduitSuivant(Produit* produit);
};



#endif 

