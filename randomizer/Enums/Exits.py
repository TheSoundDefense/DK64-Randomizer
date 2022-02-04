"""Exit enum."""
from enum import IntEnum, auto


class Exits(IntEnum):
    """Exit enum, specifically for shufflable exits."""

    # Level entrances
    IslesToJapes = auto()
    JapesToIsles = auto()
    IslesToAztec = auto()
    AztecToIsles = auto()
    IslesToFactory = auto()
    FactoryToIsles = auto()
    IslesToGalleon = auto()
    GalleonToIsles = auto()
    IslesToForest = auto()
    ForestToIsles = auto()
    IslesToCaves = auto()
    CavesToIsles = auto()
    IslesToCastle = auto()
    CastleToIsles = auto()

    # DK Isles exits
    IslesMainToStart = auto()
    IslesStartToMain = auto()
    IslesStartToTreehouse = auto()
    IslesTreehouseToStart = auto()
    IslesMainToFairy = auto()
    IslesFairyToMain = auto()
    IslesMainToSnideRoom = auto()
    IslesSnideRoomToMain = auto()
    IslesMainToJapesLobby = auto()
    IslesJapesLobbyToMain = auto()
    IslesMainToAztecLobby = auto()
    IslesAztecLobbyToMain = auto()
    IslesMainToFactoryLobby = auto()
    IslesFactoryLobbyToMain = auto()
    IslesMainToGalleonLobby = auto()
    IslesGalleonLobbyToMain = auto()
    IslesMainToForestLobby = auto()
    IslesForestLobbyToMain = auto()
    IslesMainToCavesLobby = auto()
    IslesCavesLobbyToMain = auto()
    IslesMainToCastleLobby = auto()
    IslesCastleLobbyToMain = auto()
    IslesMainToHelmLobby = auto()
    IslesHelmLobbyToMain = auto()

    # Jungle Japes Exits
    JapesMainToMine = auto()
    JapesMineToMain = auto()
    JapesMainToLankyCave = auto()
    JapesLankyCaveToMain = auto()
    JapesMainToCatacomb = auto()
    JapesCatacombToMain = auto()
    JapesMainToTinyHive = auto()
    JapesTinyHiveToMain = auto()
    JapesMineToCarts = auto()
    JapesCartsToMine = auto()

    # Angry Aztec Exits
    AztecStartToTemple = auto()
    AztecTempleToStart = auto()
    AztecMainToDonkey = auto()
    AztecDonkeyToMain = auto()
    AztecMainToDiddy = auto()
    AztecDiddyToMain = auto()
    AztecMainToLanky = auto()
    AztecLankyToMain = auto()
    AztecMainToTiny = auto()
    AztecTinyToMain = auto()
    AztecMainToChunky = auto()
    AztecChunkyToMain = auto()
    AztecMainToRace = auto()
    AztecRaceToMain = auto()
    AztecMainToLlama = auto()
    AztecLlamaToMain = auto()

    # Frantic Factory Exits
    FactoryRandDToRace = auto()
    FactoryRaceToRandD = auto()
    FactoryChunkyRoomToPower = auto()
    FactoryPowerToChunkyRoom = auto()
    FactoryBeyondHatchToInsideCore = auto()
    FactoryInsideCoreToBeyondHatch = auto()

    # Gloomy Galleon Exits
    GalleonLighthouseAreaToLighthouse = auto()
    GalleonLighthouseToLighthouseArea = auto()
    GalleonLighthousAreaToMermaid = auto()
    GalleonMermaidToLighthouseArea = auto()
    GalleonLighthouseAreaToSickBay = auto()
    GalleonSickBayToLighthouseArea = auto()
    GalleonShipyardToSeal = auto()
    GalleonSealToShipyard = auto()
    GalleonShipyardToSubmarine = auto()
    GalleonSubmarineToShipyard = auto()
    GalleonShipyardToLanky = auto()
    GalleonLankyToShipyard = auto()
    GalleonShipyardToTiny = auto()
    GalleonTinyToShipyard = auto()
    GalleonShipyardToBongos = auto()
    GalleonBongosToShipyard = auto()
    GalleonShipyardToGuitar = auto()
    GalleonGuitarToShipyard = auto()
    GalleonShipyardToTrombone = auto()
    GalleonTromboneToShipyard = auto()
    GalleonShipyardToSaxophone = auto()
    GalleonSaxophoneToShipyard = auto()
    GalleonShipyardToTriangle = auto()
    GalleonTriangleToShipyard = auto()
    GalleonTreasureToChest = auto()
    GalleonChestToTreasure = auto()

    # Fungi Forest Exits
    ForestMainToCarts = auto()
    ForestCartsToMain = auto()
    ForestMainToLowerMushroom = auto()
    ForestLowerMushroomToMain = auto()
    ForestLowerExteriorToLowerMushroom = auto()
    ForestLowerMushroomToLowerExterior = auto()
    ForestLowerExteriorToUpperMushroom = auto()
    ForestUpperMushroomToLowerExterior = auto()
    ForestUpperExteriorToUpperMushroom = auto()
    ForestUpperMushroomToUpperExterior = auto()
    ForestExteriorToNight = auto()
    ForestNightToExterior = auto()
    ForestExteriorToChunky = auto()
    ForestChunkyToExterior = auto()
    ForestExteriorToZingers = auto()
    ForestZingersToExterior = auto()
    ForestExteriorToMushrooms = auto()
    ForestMushroomsToExterior = auto()
    ForestTreeToAnthill = auto()
    ForestAnthillToTree = auto()
    ForestMainToChunkyMill = auto()
    ForestChunkyMillToMain = auto()
    ForestMainToTinyMill = auto()
    ForestTinyMillToMain = auto()
    ForestMainToGrinder = auto()
    ForestGrinderToMain = auto()
    ForestMainToRafters = auto()
    ForestRaftersToMain = auto()
    ForestMainToWinch = auto()
    ForestWinchToMain = auto()
    ForestMainToAttic = auto()
    ForestAtticToMain = auto()
    ForestTinyMillToSpider = auto()
    ForestSpiderToTinyMill = auto()
    ForestTinyMillToGrinder = auto()
    ForestGrinderToTinyMill = auto()
    ForestMainToBarn = auto()
    ForestBarnToMain = auto()

    # Crystal Caves Exits
    CavesMainToRace = auto()
    CavesRaceToMain = auto()
    CavesMainToCastle = auto()
    CavesCastleToMain = auto()
    CavesIglooToDonkey = auto()
    CavesDonkeyToIgloo = auto()
    CavesIglooToDiddy = auto()
    CavesDiddyToIgloo = auto()
    CavesIglooToLanky = auto()
    CavesLankyToIgloo = auto()
    CavesIglooToTiny = auto()
    CavesTinyToIgloo = auto()
    CavesIglooToChunky = auto()
    CavesChunkyToIgloo = auto()
    CavesCabinToRotating = auto()
    CavesRotatingToCabin = auto()
    CavesCabinToDonkey = auto()
    CavesDonkeyToCabin = auto()
    CavesCabinToDiddyLower = auto()
    CavesDiddyLowerToCabin = auto()
    CavesCabinToDiddyUpper = auto()
    CavesDiddyUpperToCabin = auto()
    CavesCabinToLanky = auto()
    CavesLankyToCabin = auto()
    CavesCabinToTiny = auto()
    CavesTinyToCabin = auto()
    CavesCabinToChunky = auto()
    CavesChunkyToCabin = auto()

    # Creepy Castle Exits
    CastleMainToTree = auto()
    CastleTreeToMain = auto()
    CastleTreeDrainToMain = auto()
    CastleMainToLibrary = auto()
    CastleLibraryToMain = auto()
    CastleMainToBallroom = auto()
    CastleBallroomToMain = auto()
    CastleMainToTower = auto()
    CastleTowerToMain = auto()
    CastleMainToGreenhouse = auto()
    CastleGreenhouseToMain = auto()
    CastleMainToTrash = auto()
    CastleTrashToMain = auto()
    CastleMainToShed = auto()
    CastleShedToMain = auto()
    CastleMainToMuseum = auto()
    CastleMuseumToMain = auto()
    CastleMainToLower = auto()
    CastleLowerToMain = auto()
    CastleMainToUpper = auto()
    CastleUpperToMain = auto()
    CastleWaterfallToUpper = auto()
    CastleUpperToWaterfall = auto()
    CastleBallroomToRace = auto()
    CastleRaceToBallroom = auto()
    CastleLowerToCrypt = auto()
    CastleCryptToLower = auto()
    CastleLowerToMausoleum = auto()
    CastleMausoleumToLower = auto()
    CastleCryptToCarts = auto()
    CastleCartsToCrypt = auto()
    CastleUpperToDungeon = auto()
    CastleDungeonToUpper = auto()
