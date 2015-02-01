#ifndef OPENCS_VIEW_NAVIGATION1ST_H
#define OPENCS_VIEW_NAVIGATION1ST_H

#include "navigation.hpp"

class QPoint;
namespace Ogre {
class Camera;
}  // namespace Ogre

namespace CSVRender
{
    /// \brief First person-like camera controls
    class Navigation1st : public Navigation
    {
            Ogre::Camera *mCamera;

        public:

            Navigation1st();

            virtual bool activate (Ogre::Camera *camera);
            ///< \return Update required?

            virtual bool wheelMoved (int delta);
            ///< \return Update required?

            virtual bool mouseMoved (const QPoint& delta, int mode);
            ///< \param mode: 0: default mouse key, 1: default mouse key and modifier key 1
            /// \return Update required?

            virtual bool handleMovementKeys (int vertical, int horizontal);
            ///< \return Update required?

            virtual bool handleRollKeys (int delta);
            ///< \return Update required?
    };
}

#endif
