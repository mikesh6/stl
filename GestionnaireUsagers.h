/********************************************
* Titre: Travail pratique #5 - GestionnaireUsagers.h
* Date: 9 mars 2018
* Auteur: Ryan Hardie
*******************************************/

#pragma once

#include "GestionnaireGenerique.h"
#include "set"

//typename set with or without


class GestionnaireUsagers : public GestionnaireGenerique <Usager,FoncteurAjouterUsager,set<Usager*>, FoncteurSupprimerUsager> {

public:

	GestionnaireUsagers();
	double obtenirChiffreAffaires() const;
	void encherir(Client *client, ProduitAuxEncheres *produit, double montant) const;
	void reinitialiser();
	void afficherProfils() const;
	
};
