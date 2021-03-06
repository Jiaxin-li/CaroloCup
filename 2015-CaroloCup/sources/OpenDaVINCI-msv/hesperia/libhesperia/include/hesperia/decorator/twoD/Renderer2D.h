/*
 * Copyright (c) Christian Berger and Bernhard Rumpe, Rheinisch-Westfaelische Technische Hochschule Aachen, Germany.
 *
 * The Hesperia Framework.
 */

#ifndef HESPERIA_CORE_DECORATOR_TWOD_RENDERER2D_H_
#define HESPERIA_CORE_DECORATOR_TWOD_RENDERER2D_H_

#include <vector>

// native.h must be included as first header file for definition of _WIN32_WINNT.
#include "core/native.h"

#include "hesperia/decorator/Renderer.h"

namespace hesperia {
    namespace decorator {
        namespace twoD {

            using namespace std;

            /**
             * This class decorates any primitive data structure for rendering
             * with a two-dimensional context. Thus, the concrete two-dimensional
             * context must derive from this class and implement the missing
             * methods.
             */
            class OPENDAVINCI_API Renderer2D : public hesperia::decorator::Renderer {
                public:
                    Renderer2D();

                    virtual ~Renderer2D();

                public:
                    virtual void setColor(const core::data::environment::Point3 &c) = 0;

                    virtual void setPointWidth(const double &width) = 0;

                    virtual void setLineWidth(const double &width) = 0;

                    virtual void drawText(const core::data::environment::Point3 &p, const string &text) = 0;

                    virtual void drawLine(const core::data::environment::Point3 &A, const core::data::environment::Point3 &B) = 0;

                    virtual void drawPoint(const core::data::environment::Point3 &p) = 0;

                    virtual void drawImage(const core::wrapper::Image *image, const core::data::environment::Point3 &originPixelXY, const core::data::environment::Point3 &scalingPixelXY, const float &rotationZ) = 0;

                    virtual void beginPainting();

                    virtual void endPainting();

                    virtual void drawPolyLine(const vector<core::data::environment::Point3> &listOfPoints);

                    virtual void drawPolyLine(const vector<core::data::environment::Point3> &listOfPoints, const double &height);

                    virtual void drawTriangleSet(const hesperia::decorator::models::TriangleSet &ts);

                    virtual void drawListOfTriangleSets(const vector<hesperia::decorator::models::TriangleSet> &listOfTriangleSets);

                    virtual void drawTriangleSet(const hesperia::decorator::models::TriangleSet &ts, const core::data::environment::Point3 &position, const core::data::environment::Point3 &rotation);

                    virtual void drawListOfTriangleSets(const vector<hesperia::decorator::models::TriangleSet> &listOfTriangleSets, const core::data::environment::Point3 &position, const core::data::environment::Point3 &rotation);
            };

        }
    }
} // hesperia::decorator::twoD

#endif /*HESPERIA_CORE_DECORATOR_TWOD_RENDERER2D_H_*/
