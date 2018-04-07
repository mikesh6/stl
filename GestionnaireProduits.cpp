/********************************************
* Titre: Travail pratique #5 - GestionnaireProduits.cpp
* Date: 9 mars 2018
* Auteur: Ryan Hardie
*******************************************/

#include "GestionnaireProduits.h"
#include "ProduitAuxEncheres.h"
using namespace std;


GestionnaireProduits::GestionnaireProduits()
{
}

void GestionnaireProduits::reinitialiserClient()
{

	for (auto i : conteneur_) {
		(dynamic_cast<ProduitAuxEncheres *>(i.second))->modifierEncherisseur(nullptr);
		i.second->modifierPrix(i.second->obtenirPrix());
	}


	conteneur_.clear();


}

void GestionnaireProduits::reinitialiserFournisseur()
{

	for (auto i : conteneur_) {
		(dynamic_cast<ProduitAuxEncheres*>(i.second))->modifierEncherisseur(nullptr);
		i.second->modifierPrix(i.second->obtenirPrix());
	}

	conteneur_.clear();
}

void GestionnaireProduits::afficher() const
{

	for (auto i : conteneur_) {
		i.second->afficher();
	}


}

double GestionnaireProduits::obtenirTotalAPayer(multimap<int, Produit*> monProduit)
{
	double total = 0.0;
	for (auto i : conteneur_)
		total += i.second->obtenirPrix();

	return total; //?
}

double GestionnaireProduits::obtenirTotalApayerPremium()
{
	double total = 0;
	for (auto i : conteneur_) {
		if (i.second->obtenirPrix() > 5) {
			total -= 5;
		}
		else
			total += i.second->obtenirPrix();

	}
	return total;
}

Produit * GestionnaireProduits::trouverProduitPlusCher()
{
	auto ProduitPlusCher = max_element(conteneur_.begin(), conteneur_.end(),
		[](pair<int, Produit*> &gauche, pair<int, Produit*> &droite) -> bool// does this take iterators
	{
		return (gauche.second->obtenirPrix() < droite.second->obtenirPrix());
	});
	return ProduitPlusCher->second;
}

vector<pair<int, Produit*>> GestionnaireProduits::obtenirProduitsEntre(double lowerR, double upperR)
{
	//vector<pair<int, Produit*> > vec;
	//copy_if(conteneur_.begin(), conteneur_.end(), back_inserter(vec), FoncteurIntervalle(borneInf, borneSup));
	//return vector<pair<int, Produit*>>;
}

Produit * GestionnaireProduits::obtenirProduitSuivant(Produit * produit)
{
	//auto it = find_if(conteneur_.begin(), conteneur_.end(), bind(greater<pair<int, Produit*> >(), placeholders::_1, pair<int, Produit*>(prod->obtenirPrix(), prod)));
	//return it->second;
}
