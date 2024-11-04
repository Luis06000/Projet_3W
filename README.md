# Station Météo Arduino

## Description
Ce projet est une station météo basée sur Arduino qui permet de collecter et d'enregistrer différentes données environnementales. La station dispose de plusieurs modes de fonctionnement et peut mesurer :

- Température
- Humidité
- Pression atmosphérique
- Luminosité
- Position GPS

## Caractéristiques

### Modes de fonctionnement
- **Mode Standard** : Enregistrement normal des données
- **Mode Economy** : Enregistrement alterné des données GPS pour économiser l'énergie
- **Mode Maintenance** : Affichage des données en temps réel sur le port série
- **Mode Configuration** : Configuration des paramètres via le port série

### Composants matériels
- Arduino (compatible)
- Capteur BME280 (température, humidité, pression)
- Module GPS Air530
- Grove Light Sensor
- Module RTC DS1307
- SD Card Shield V4.0
- Base Shield V2
- LED RGB Chainable
- Grove Dual Button

## Installation

1. Ouvrez un terminal et positionnez-vous dans le répertoire où vous souhaitez installer le projet :
   ```bash
   cd chemin/vers/votre/dossier
   ```

2. Clonez le dépôt :
   ```bash
   git clone https://github.com/Luis06000/Projet_3W.git
   cd Projet_3W
   ```

3. Exécutez le script d'auto-compilation :
   ```bash
   AutoCompil.bat
   ```

## Schéma de câblage

### Structure générale
```

                                                └── [GPS] (D2)
                                                └── [Dual Button] (D3)
[Arduino UNO] <== [SD Shield] <== [Base Shield] <── [RGB LED] (D7)
                                                └── [Light Sensor] (A0)
                                                └── [RTC] (I2C)
                                                └── [BME280] (I2C)
```

### Détails des connexions
1. **Empilage des shields (de bas en haut)**:
   - Arduino UNO (base)
   - SD Card Shield V4.0
   - Base Shield V2

2. **Connexions sur le Base Shield**:
   - Port I2C : BME280 et RTC
   - Port D7 : LED RGB Chainable
   - Port D3 : Grove Dual Button
   - Port D2 : GPS Air530
   - Port A0 : Grove Light Sensor

## Configuration

Les paramètres configurables incluent :
- Intervalles d'enregistrement
- Seuils des capteurs
- Taille maximale des fichiers
- Timeout GPS
- Activation/désactivation des capteurs

## Utilisation

### Contrôles
- **Bouton 1** (maintenu) : Basculer entre mode Standard et Economy
- **Bouton 2** (maintenu) : Basculer vers/depuis le mode Maintenance
- **Bouton 2** au démarrage : Entrer en mode Configuration

### Indicateurs LED
- **Vert** : Mode Standard
- **Bleu** : Mode Economy
- **Orange** : Mode Maintenance
- **Jaune** : Mode Configuration
- **Rouge** : Erreur

### Format des données
Les données sont enregistrées sur la carte SD au format :
DD/MM/YYYY HH:MM:SS Lumière:XXX T:XX.XX °C H:XX.XX % P:XXXX.XX hPa Latitude:XX.XXXXXX Longitude:XX.XXXXXX

## Gestion des erreurs
- Surveillance des erreurs de capteurs
- Détection de carte SD pleine
- Validation des données GPS
- Rotation automatique des fichiers logs

## Maintenance
- Vérifiez régulièrement l'espace disponible sur la carte SD
- Calibrez les capteurs si nécessaire
- Mettez à jour l'heure RTC si nécessaire
