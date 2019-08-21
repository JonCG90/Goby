#-------------------------------------------------
#
# Project created by QtCreator 2019-02-04T21:32:56
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Goby
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

INCLUDEPATH += \
            src \
            src/thirdparty \
            /usr/local/opt/USD/include

LIBS += \
     -L/usr/local/opt/USD/lib -lusd_ms

SOURCES += \
    src/app/actions/action.cpp \
    src/app/actions/actionManager.cpp \
    src/app/actions/cameraActions.cpp \
    src/app/camera/camera.cpp \
    src/app/camera/cameraController.cpp \
    src/coral/schema/cameraSchema.cpp \
    src/coral/schema/meshSchema.cpp \
    src/coral/item.cpp \
    src/coral/scene.cpp \
    src/coral/transform.cpp \
    src/math/conversion.cpp \
    src/math/math.cpp \
    src/rendering/marlin/geometry/geometry.cpp \
    src/rendering/marlin/geometry/mesh.cpp \
    src/rendering/marlin/geometry/meshUtilities.cpp \
    src/rendering/marlin/gl/buffer.cpp \
    src/rendering/marlin/gl/shader.cpp \
    src/rendering/marlin/gl/vertexArray.cpp \
    src/rendering/marlin/shading/material.cpp \
    src/rendering/marlin/shading/shaderParameter.cpp \
    src/rendering/marlin/usd/renderDelegate.cpp \
    src/rendering/marlin/usd/rendererPlugin.cpp \
    src/thirdparty/glm/detail/dummy.cpp \
    src/thirdparty/glm/detail/glm.cpp \
    src/ui/mainWindow.cpp \
    src/ui/openglwindow.cpp \
    src/ui/usdRenderWindow.cpp \
    src/main.cpp \
    src/app/shortcuts/shortcutFilter.cpp \
    src/app/shortcuts/shortcutManager.cpp \
    src/app/shortcuts/shortcutReceiver.cpp

HEADERS += \
    src/app/actions/action.hpp \
    src/app/actions/actionManager.hpp \
    src/app/actions/cameraActions.hpp \
    src/app/camera/camera.hpp \
    src/app/camera/cameraController.hpp \
    src/coral/schema/cameraSchema.hpp \
    src/coral/schema/meshSchema.hpp \
    src/coral/item.hpp \
    src/coral/scene.hpp \
    src/coral/transform.hpp \
    src/math/conversion.hpp \
    src/math/defs.hh \
    src/math/math.hpp \
    src/rendering/marlin/geometry/geometry.hpp \
    src/rendering/marlin/geometry/mesh.hpp \
    src/rendering/marlin/geometry/meshUtilities.hpp \
    src/rendering/marlin/gl/buffer.hpp \
    src/rendering/marlin/gl/buffer.tpp \
    src/rendering/marlin/gl/shader.hpp \
    src/rendering/marlin/gl/vertexArray.hpp \
    src/rendering/marlin/shading/material.hpp \
    src/rendering/marlin/shading/material.tpp \
    src/rendering/marlin/shading/shaderParameter.hpp \
    src/rendering/marlin/shading/shaderParameter.tpp \
    src/rendering/marlin/usd/renderDelegate.hpp \
    src/rendering/marlin/usd/rendererPlugin.hpp \
    src/thirdparty/glm/detail/_features.hpp \
    src/thirdparty/glm/detail/_fixes.hpp \
    src/thirdparty/glm/detail/_noise.hpp \
    src/thirdparty/glm/detail/_swizzle.hpp \
    src/thirdparty/glm/detail/_swizzle_func.hpp \
    src/thirdparty/glm/detail/_vectorize.hpp \
    src/thirdparty/glm/detail/func_common.hpp \
    src/thirdparty/glm/detail/func_common.inl \
    src/thirdparty/glm/detail/func_exponential.hpp \
    src/thirdparty/glm/detail/func_exponential.inl \
    src/thirdparty/glm/detail/func_geometric.hpp \
    src/thirdparty/glm/detail/func_geometric.inl \
    src/thirdparty/glm/detail/func_integer.hpp \
    src/thirdparty/glm/detail/func_integer.inl \
    src/thirdparty/glm/detail/func_matrix.hpp \
    src/thirdparty/glm/detail/func_matrix.inl \
    src/thirdparty/glm/detail/func_noise.hpp \
    src/thirdparty/glm/detail/func_noise.inl \
    src/thirdparty/glm/detail/func_packing.hpp \
    src/thirdparty/glm/detail/func_packing.inl \
    src/ui/mainWindow.hpp \
    src/ui/openglwindow.hpp \
    src/ui/usdRenderWindow.hpp \
    src/thirdparty/glm/detail/_features.hpp \
    src/thirdparty/glm/detail/_fixes.hpp \
    src/thirdparty/glm/detail/_noise.hpp \
    src/thirdparty/glm/detail/_swizzle_func.hpp \
    src/thirdparty/glm/detail/_swizzle.hpp \
    src/thirdparty/glm/detail/_vectorize.hpp \
    src/thirdparty/glm/detail/func_common.hpp \
    src/thirdparty/glm/detail/func_common.inl \
    src/thirdparty/glm/detail/func_exponential.hpp \
    src/thirdparty/glm/detail/func_exponential.inl \
    src/thirdparty/glm/detail/func_geometric.hpp \
    src/thirdparty/glm/detail/func_geometric.inl \
    src/thirdparty/glm/detail/func_integer.hpp \
    src/thirdparty/glm/detail/func_integer.inl \
    src/thirdparty/glm/detail/func_matrix.hpp \
    src/thirdparty/glm/detail/func_matrix.inl \
    src/thirdparty/glm/detail/func_noise.hpp \
    src/thirdparty/glm/detail/func_noise.inl \
    src/thirdparty/glm/detail/func_packing.hpp \
    src/thirdparty/glm/detail/func_packing.inl \
    src/thirdparty/glm/detail/func_trigonometric.hpp \
    src/thirdparty/glm/detail/func_trigonometric.inl \
    src/thirdparty/glm/detail/func_vector_relational.hpp \
    src/thirdparty/glm/detail/func_vector_relational.inl \
    src/thirdparty/glm/detail/intrinsic_common.hpp \
    src/thirdparty/glm/detail/intrinsic_common.inl \
    src/thirdparty/glm/detail/intrinsic_exponential.hpp \
    src/thirdparty/glm/detail/intrinsic_exponential.inl \
    src/thirdparty/glm/detail/intrinsic_geometric.hpp \
    src/thirdparty/glm/detail/intrinsic_geometric.inl \
    src/thirdparty/glm/detail/intrinsic_integer.hpp \
    src/thirdparty/glm/detail/intrinsic_integer.inl \
    src/thirdparty/glm/detail/intrinsic_matrix.hpp \
    src/thirdparty/glm/detail/intrinsic_matrix.inl \
    src/thirdparty/glm/detail/intrinsic_trigonometric.hpp \
    src/thirdparty/glm/detail/intrinsic_trigonometric.inl \
    src/thirdparty/glm/detail/intrinsic_vector_relational.hpp \
    src/thirdparty/glm/detail/intrinsic_vector_relational.inl \
    src/thirdparty/glm/detail/precision.hpp \
    src/thirdparty/glm/detail/setup.hpp \
    src/thirdparty/glm/detail/type_float.hpp \
    src/thirdparty/glm/detail/type_gentype.hpp \
    src/thirdparty/glm/detail/type_gentype.inl \
    src/thirdparty/glm/detail/type_half.hpp \
    src/thirdparty/glm/detail/type_half.inl \
    src/thirdparty/glm/detail/type_int.hpp \
    src/thirdparty/glm/detail/type_mat.hpp \
    src/thirdparty/glm/detail/type_mat.inl \
    src/thirdparty/glm/detail/type_mat2x2.hpp \
    src/thirdparty/glm/detail/type_mat2x2.inl \
    src/thirdparty/glm/detail/type_mat2x3.hpp \
    src/thirdparty/glm/detail/type_mat2x3.inl \
    src/thirdparty/glm/detail/type_mat2x4.hpp \
    src/thirdparty/glm/detail/type_mat2x4.inl \
    src/thirdparty/glm/detail/type_mat3x2.hpp \
    src/thirdparty/glm/detail/type_mat3x2.inl \
    src/thirdparty/glm/detail/type_mat3x3.hpp \
    src/thirdparty/glm/detail/type_mat3x3.inl \
    src/thirdparty/glm/detail/type_mat3x4.hpp \
    src/thirdparty/glm/detail/type_mat3x4.inl \
    src/thirdparty/glm/detail/type_mat4x2.hpp \
    src/thirdparty/glm/detail/type_mat4x2.inl \
    src/thirdparty/glm/detail/type_mat4x3.hpp \
    src/thirdparty/glm/detail/type_mat4x3.inl \
    src/thirdparty/glm/detail/type_mat4x4.hpp \
    src/thirdparty/glm/detail/type_mat4x4.inl \
    src/thirdparty/glm/detail/type_vec.hpp \
    src/thirdparty/glm/detail/type_vec.inl \
    src/thirdparty/glm/detail/type_vec1.hpp \
    src/thirdparty/glm/detail/type_vec1.inl \
    src/thirdparty/glm/detail/type_vec2.hpp \
    src/thirdparty/glm/detail/type_vec2.inl \
    src/thirdparty/glm/detail/type_vec3.hpp \
    src/thirdparty/glm/detail/type_vec3.inl \
    src/thirdparty/glm/detail/type_vec4_avx.inl \
    src/thirdparty/glm/detail/type_vec4_avx2.inl \
    src/thirdparty/glm/detail/type_vec4_sse2.inl \
    src/thirdparty/glm/detail/type_vec4.hpp \
    src/thirdparty/glm/detail/type_vec4.inl \
    src/app/shortcuts/shortcutFilter.hpp \
    src/app/shortcuts/shortcutManager.hpp \
    src/app/shortcuts/shortcutReceiver.hpp

FORMS += \
        src/ui/mainWindow.ui \
    src/ui/mainWindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    src/rendering/marlin/usd/pluginInfo.json
