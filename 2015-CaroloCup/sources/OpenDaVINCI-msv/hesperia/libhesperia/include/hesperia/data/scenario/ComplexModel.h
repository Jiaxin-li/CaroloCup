/*
 * Copyright (c) Christian Berger and Bernhard Rumpe, Rheinisch-Westfaelische Technische Hochschule Aachen, Germany.
 *
 * The Hesperia Framework.
 */

#ifndef HESPERIA_CORE_DATA_SCENARIO_COMPLEXMODEL_H_
#define HESPERIA_CORE_DATA_SCENARIO_COMPLEXMODEL_H_

// native.h must be included as first header file for definition of _WIN32_WINNT.
#include "core/native.h"

#include "hesperia/data/scenario/BoundingBox.h"
#include "hesperia/data/scenario/Shape.h"
#include "hesperia/data/scenario/Vertex3.h"

namespace hesperia {
    namespace data {
        namespace scenario {

            using namespace std;

            /**
             * This class represents a complex model.
             */
            class OPENDAVINCI_API ComplexModel : public Shape {
                public:
                    ComplexModel();

                    /**
                     * Copy constructor.
                     *
                     * @param obj Reference to an object of this class.
                     */
                    ComplexModel(const ComplexModel &obj);

                    /**
                     * Assignment operator.
                     *
                     * @param obj Reference to an object of this class.
                     * @return Reference to this instance.
                     */
                    ComplexModel& operator=(const ComplexModel &obj);

                    virtual ~ComplexModel();

                    virtual void accept(ScenarioVisitor &visitor);

                    /**
                     * This method returns the model file name containing
                     * the data for this shape.
                     *
                     * @return Model file name.
                     */
                    const string getModelFile() const;

                    /**
                     * This method sets the model file containing the
                     * data for this shape.
                     *
                     * @param modelFile Model file name.
                     */
                    void setModelFile(const string &modelFile);

                    /**
                     * This method returns the position of this shape
                     * (center of mass).
                     *
                     * @return Position (center of mass).
                     */
                    const Vertex3& getPosition() const;

                    /**
                     * This method sets the position of this shape
                     * (center of mass).
                     *
                     * @param position Position (center of mass).
                     */
                    void setPosition(const Vertex3 &position);

                    /**
                     * This method returns the rotation of this shape.
                     *
                     * @return Rotation.
                     */
                    const Vertex3& getRotation() const;

                    /**
                     * This method sets the rotation of this shape.
                     *
                     * @param rotation Rotation.
                     */
                    void setRotation(const Vertex3 &rotation);

                    /**
                     * This method returns the bounding box.
                     *
                     * @return Bounding box.
                     */
                    const BoundingBox& getBoundingBox() const;

                    /**
                     * This method sets the bounding box.
                     *
                     * @param bb Bounding box.
                     */
                    void setBoundingBox(const BoundingBox &bb);

                    virtual ostream& operator<<(ostream &out) const;
                    virtual istream& operator>>(istream &in);

                    virtual const string toString() const;

                private:
                    string m_modelFile;
                    Vertex3 m_position;
                    Vertex3 m_rotation;
                    BoundingBox m_boundingBox;
            };

        }
    }
} // hesperia::data::scenario

#endif /*HESPERIA_CORE_DATA_SCENARIO_COMPLEXMODEL_H_*/
