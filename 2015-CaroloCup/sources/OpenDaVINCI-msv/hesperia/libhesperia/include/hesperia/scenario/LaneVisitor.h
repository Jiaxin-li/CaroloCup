/*
 * Copyright (c) Christian Berger and Bernhard Rumpe, Rheinisch-Westfaelische Technische Hochschule Aachen, Germany.
 *
 * The Hesperia Framework.
 */

#ifndef HESPERIA_SCENARIO_LANEVISITOR_H_
#define HESPERIA_SCENARIO_LANEVISITOR_H_

#include "core/native.h"

#include "core/wrapper/graph/DirectedGraph.h"
#include "core/wrapper/graph/Edge.h"

#include "hesperia/data/environment/NamedLine.h"
#include "hesperia/data/scenario/PointModel.h"
#include "hesperia/data/scenario/StraightLine.h"
#include "hesperia/data/scenario/Arc.h"
#include "hesperia/data/scenario/ScenarioVisitor.h"
#include "hesperia/data/scenario/Scenario.h"

namespace hesperia {
    namespace scenario {

        using namespace std;

        /**
         * This class implements a visitor for constructing the graph.
         */
        class LaneVisitor : public hesperia::data::scenario::ScenarioVisitor {
            private:
                /**
                 * "Forbidden" copy constructor. Goal: The compiler should warn
                 * already at compile time for unwanted bugs caused by any misuse
                 * of the copy constructor.
                 *
                 * @param obj Reference to an object of this class.
                 */
                LaneVisitor(const LaneVisitor &/*obj*/);

                /**
                 * "Forbidden" assignment operator. Goal: The compiler should warn
                 * already at compile time for unwanted bugs caused by any misuse
                 * of the assignment operator.
                 *
                 * @param obj Reference to an object of this class.
                 * @return Reference to this instance.
                 */
                LaneVisitor& operator=(const LaneVisitor &/*obj*/);

            public:
                /**
                 * Constructor.
                 *
                 * @param g Graph.
                 * @param scenario Scenario.
                 */
                LaneVisitor(core::wrapper::graph::DirectedGraph &g, hesperia::data::scenario::Scenario &scenario);

                virtual ~LaneVisitor();

                virtual void visit(hesperia::data::scenario::ScenarioNode &node);

                vector<hesperia::data::environment::NamedLine> getListOfLines() const;

            private:
                core::wrapper::graph::DirectedGraph &m_graph;
                hesperia::data::scenario::Scenario &m_scenario;

                // This vector contains all line between start and end points from lanes (arcs are approximated).
                vector<hesperia::data::environment::NamedLine> m_listOfLines;

                /**
                 * This method is called by the generic visit method.
                 *
                 * @param pm PointModel to visit.
                 */
                void visit(const hesperia::data::scenario::PointModel *pm);

                /**
                 * This method is called by the generic visit method.
                 *
                 * @param sl StraightLine to visit. Covers also arcs.
                 */
                void visit(const hesperia::data::scenario::StraightLine *sl);

                /**
                 * This method is called by the generic visit method.
                 *
                 * @param arc Arc to visit. Covers also arcs.
                 */
                void visit(const hesperia::data::scenario::Arc *arc);
        };

    }
} // hesperia::scenario

#endif /*HESPERIA_SCENARIO_LANEVISITOR_H_*/
