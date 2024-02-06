include(FetchContent)
FetchContent_Declare(Paradox-Platform
    GIT_REPOSITORY "https://github.com/ParadoxGene/Paradox-Platform.git"
    GIT_TAG "main"   # it's much better to use a specific Git revision or Git tag for reproducibility
    SOURCE_DIR ${PROJECT_DIR}/modules/Paradox-Platform   
)
FetchContent_Populate(Paradox-Platform)