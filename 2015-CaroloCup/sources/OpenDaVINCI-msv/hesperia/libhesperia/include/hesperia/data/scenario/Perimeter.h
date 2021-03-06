/*
 * Copyright (c) Christian Berger and Bernhard Rumpe, Rheinisch-Westfaelische Technische Hochschule Aachen, Germany.
 *
 * The Hesperia Framework.
 */

#ifndef HESPERIA_CORE_DATA_SCENARIO_PERIMETER_H_
#define HESPERIA_CORE_DATA_SCENARIO_PERIMETER_H_

#include <string>
#include <vector>

// native.h must be included as first header file for definition of _WIN32_WINNT.
#include "core/native.h"

#include "core/data/SerializableData.h"
#include "hesperia/data/scenario/IDVertex3.h"
#include "hesperia/data/scenario/ScenarioNode.h"
#include "hesperia/data/scenario/ScenarioVisitor.h"

namespace hesperia {
    namespace data {
        namespace scenario {

            using namespace std;

            /**
             * This class represents a road.
             */
            class OPENDAVINCI_API Perimeter : public core::data::SerializableData, public ScenarioNode {
                public:
                    Perimeter();

                    virtual ~Perimeter();

                    /**
                     * Copy constructor.
                     *
                     * @param obj Reference to an object of this class.
                     */
                    Perimeter(const Perimeter &obj);

                    /**
                     * Assignment operator.
                     *
                     * @param obj Reference to an object of this class.
                     * @return Reference to this instance.
                     */
                    Perimeter& operator=(const Perimeter &obj);

                    virtual void accept(scenario::ScenarioVisitor &visitor);

                    /**
                     * This method returns the list of identifiable vertices.
                     *
                     * @return List of identifiable vertices.
                     */
                    const vector<IDVertex3>& getListOfIdentifiableVertices() const;

                    /**
                     * This method adds an identifiable vertex.
                     *
                     * @param idV Identifiable vertex to be added.
                     */
                    void addIdentifiableVertex(const IDVertex3 &idV);

                    virtual ostream& operator<<(ostream &out) const;
                    virtual istream& operator>>(istream &in);

                    virtual const string toString() const;

                private:
                    vector<IDVertex3> m_listOfIdentifiableVertices;

                    /**
                     * This method creates a deep copy.
                     *
                     * @param obj Object of another instance of this class.
                     */
                    void deepCopy(const Perimeter &obj);
            };

        }
    }
} // hesperia::data::scenario

#endif /*HESPERIA_CORE_DATA_SCENARIO_PERIMETER_H_*/
