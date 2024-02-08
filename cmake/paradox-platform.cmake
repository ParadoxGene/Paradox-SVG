include(FetchContent)
FetchContent_Declare(Paradox-Platform
    GIT_REPOSITORY "https://github.com/ParadoxGene/Paradox-Platform.git"
    GIT_TAG "main"
    SOURCE_DIR ${PROJECT_DIR}/modules/Paradox-Platform   
)
FetchContent_Populate(Paradox-Platform)