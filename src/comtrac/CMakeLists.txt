cmake_minimum_required(VERSION 3.16)

project(comtrac VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 6.4 REQUIRED COMPONENTS Quick)
find_package(Qt6 REQUIRED COMPONENTS Sql)




qt_standard_project_setup()

qt_add_executable(appcomtrac
    main.cpp
    #Controllers
    Controllers/symptomdiary.cpp
    Controllers/symptomdiary.h
    Controllers/login.cpp
    Controllers/login.h
    Controllers/medication.cpp
    Controllers/medication.h
    #Models
    Models/loginModel.cpp
    Models/loginModel.h
    Models/dbManager.h
    Models/dbManager.cpp

)

qt_add_qml_module(appcomtrac
    URI comtrac
    VERSION 1.0
    QML_FILES
    Ui/Main.qml
    #Pages
    Ui/HomeScreen.qml
    Ui/Login.qml
    Ui/Medication.qml
    Ui/Chat.qml
    Ui/VideoTelephony.qml
    Ui/SymptomDiary.qml
    Ui/editSymptom.qml
    Ui/findSymptom.qml
    Ui/editMedication.qml
    Ui/findMedication.qml
    #elements
    Ui/StackViewPage.qml
    Ui/TextFieldTemplate.qml
    Ui/ButtonTemplate.qml
    Ui/SideMenu.qml
    Ui/HeaderTemplate.qml
    Ui/RadioButtonTemplate.qml
    Ui/SwitchTemplate.qml
    Ui/SliderTemplate.qml
    Ui/TimePickerTemplate.qml
    Ui/CalendarTemplate.qml
    Ui/PopupTemplate.qml
    Ui/ComboBoxTemplate.qml
    Ui/RoundButtonTemplate.qml

    RESOURCES
    assets/menu.png



)

set_target_properties(appcomtrac PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(appcomtrac
    PRIVATE Qt6::Quick
)
target_link_libraries(appcomtrac PRIVATE Qt6::Sql)




install(TARGETS appcomtrac
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})



