/********************************************
* Titre: Travail pratique #5 - GestionnaireProduits.h
* Date: 9 mars 2018
* Auteur: Ryan Hardie
*******************************************/

#pragma once

#include "GestionnaireGenerique.h"


template <class FoncteurEgal, class InputIterator>
class GestionnaireProduits : public GestionnaireGenerique <Usager, FoncteurAjouterProduit, multimap<int, Produit*>, FoncteurSupprimerProduit> {

	void reinitialiserClient(); 
	void reinitialiserFournisseur();
	void afficher() const;
	double obtenirTotalAPayer(multimap<int, Produit*> monProduit);
	double obtenirTotalApayerPremium();
    Produit* trouverProduitPlusCher();
	vector<pair<int, Produit*>> obtenirProduitsEntre(double lowerR, double upperR);
	Produit* obtenirProduitSuivant(Produit* produit);
};



