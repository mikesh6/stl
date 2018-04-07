/********************************************
* Titre: Travail pratique #5 - GestionnaireUsagers.cpp
* Date: 9 mars 2018
* Auteur: Ryan Hardie
*******************************************/
#include "ProduitAuxEncheres.h"
#include "GestionnaireUsagers.h"



double GestionnaireUsagers::obtenirChiffreAffaires() const
{
	double chiffreAffaires = 0.0;
	for (auto i : conteneur_)
		chiffreAffaires += i->obtenirTotalAPayer();
	return chiffreAffaires;
}

void GestionnaireUsagers::encherir(Client * client, ProduitAuxEncheres * produit, double montant) const
{
	if (produit->obtenirPrix() < montant)
		produit->mettreAJourEnchere(client, montant);
}

void GestionnaireUsagers::reinitialiser()
{
	for (auto i : conteneur_) {

		i->reinitialiser();

	}
}

void GestionnaireUsagers::afficherProfils() const
{
	//not completed yet
}
