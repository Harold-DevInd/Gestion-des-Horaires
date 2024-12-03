# Gestion-des-Horaires

## Etape 1 : Creation de la Classe Event

Un des éléments de base de l'application est la notion d’événement (« Event »). Un 
événement est « quelque chose » qui se produit un certain jour, à une certaine heure, à un certain 
endroit et qui dure un certain temps. Dans cette première étape, nous allons commencer par aborder 
le « quoi ? ». Les notions de « où ? »  et « quand ? ».

## Etape 2 : Creation des Classes Time et Timing

Nous allons à présent ajouter à notre classe Event tout ce qui est nécessaire à la gestion du temps, 
c’est-à-dire « Quel jour ? », « A quelle heure ? » et « Combien de temps ? : **Time** et **Timing**.

## Etape 3 : Surcharge des operateurs

Il s’agit ici, de surcharger un certain nombre d’opérateurs des classes développées ci-dessus afin 
de faciliter la gestion des heures et durées. 

## Etape 4 : Creation des classes representant des personnes

Nous allons à présent passer la modélisation des intervenants du type « Qui peut avoir un 
horaire ? Qui est occupé pendant cette tranche horaire ? etc… » : **Schedulable**, **Professor**, **Classroom** et **Group**.

## Etape 5 : Gestion des exceptions pour les classes Time et Timing

Ici nous allons mettre en place une structure minimale de gestion des erreurs propres aux 
classes développées jusqu'ici, grace aux classes : **Exception**, **TimeException** et **TimingException**.

## Etape 6 :  sérialisation des objets

Le but de cette étape est de mettre en place la sérialisation des objets de notre application : a partir de maintenant, ce sont les opérateurs << et >> de nos différents objets qui assureront 
respectivement la sérialisation et la désérialisation de nos objets sur un flux. Dans la suite, si on 
désire afficher un objet en console à l’aide de « cout << … », on utilisera plutôt la méthode 
toString() de chaque objet.

**Pour les objets Classroom :**
```xml
<Classroom> 
<id> 
5 
</id> 
<name> 
AN 
</name> 
<seatingCapacity> 
110 
</seatingCapacity> 
</Classroom>  
```

**Pour les objets Time :**
```xml
<Time> 
<hour> 
8 
</hour> 
<minute> 
20 
</minute> 
</Time> 
```
**Pour les objets Timing :**
```xml
<Timing> 
<day> 
Mardi 
</day> 
<start> 
<Time> 
<hour> 
8 
</hour> 
<minute> 
20 
</minute> 
</Time> 
</start> 
<duration> 
<Time> 
<hour> 
2 
</hour> 
<minute> 
0 
</minute>
</Time> 
</duration> 
</Timing>  
```

**Pour les objets Event :**
```xml
<Event> 
<code> 
17 
</code> 
<title> 
Labo C++ 
</title> 
<timing> 
<Timing> 
<day> 
Mardi 
</day> 
<start> 
<Time> 
<hour> 
10 
</hour> 
<minute> 
30 
</minute> 
</Time> 
</start> 
<duration> 
<Time> 
<hour> 
2 
</hour> 
<minute> 
0 
</minute> 
</Time> 
</duration> 
</Timing>
</timing>  
</Event>  
```

> N'oublier par de créer le repertoire Objets
