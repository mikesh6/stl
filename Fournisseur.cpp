#include "Fournisseur.h"
#include "GestionnaireProduits.h"

#include <iostream>

using namespace std;

Fournisseur::Fournisseur():Usager()
{
	catalogue_ = new GestionnaireProduits;
}

Fournisseur::Fournisseur(const string & nom, const string & prenom, int identifiant, const string & codePostal):
	Usager(nom, prenom, identifiant, codePostal)
	
{
	catalogue_ = new GestionnaireProduits;
}

Fournisseur::~Fournisseur()
{

	delete catalogue_;
}

GestionnaireProduits * Fournisseur::obtenirCatalogue() const
{
	return catalogue_;
}

void Fournisseur::afficherCatalogue() const
{
	cout << "CATALOGUE (de " << obtenirNom() << ")"
		<< "\n";

	catalogue_->afficher();
	cout << endl;
}

void Fournisseur::afficher() const
{

	Usager::afficher();
	cout << "\t\tcatalogue:\t" << catalogue_->obtenirConteneur().size() << " elements" << endl;

}

void Fournisseur::reinitialiser()
{

	catalogue_->reinitialiserFournisseur();
}

void Fournisseur::ajouterProduit(Produit * produit)
{
	catalogue_->ajouter(produit);
}

void Fournisseur::enleverProduit(Produit * produit)
{

//	catalogue_->supprimer(produit);
}

Produit * Fournisseur::trouverProduitPlusCher() const
{
	return nullptr;
}

void Fournisseur::DiminuerPrix(int pourcent) const
{
	FoncteurDiminuerPourcent predicat(pourcent);
	catalogue_->pourChaqueElement(predicat);
}
