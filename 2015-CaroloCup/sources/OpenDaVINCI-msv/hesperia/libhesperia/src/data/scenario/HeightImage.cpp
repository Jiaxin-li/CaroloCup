/*
 * Copyright (c) Christian Berger and Bernhard Rumpe, Rheinisch-Westfaelische Technische Hochschule Aachen, Germany.
 *
 * The Hesperia Framework.
 */

#include "core/base/Hash.h"
#include "core/base/Deserializer.h"
#include "core/base/SerializationFactory.h"
#include "core/base/Serializer.h"
#include "hesperia/data/scenario/HeightImage.h"

namespace hesperia {
    namespace data {
        namespace scenario {

            using namespace std;
            using namespace core::base;

            HeightImage::HeightImage() :
                    Image(),
                    m_groundHeight(0),
                    m_minimumHeight(0),
                    m_maximumHeight(0) {}

            HeightImage::HeightImage(const HeightImage &obj) :
                    Image(obj),
                    m_groundHeight(obj.m_groundHeight),
                    m_minimumHeight(obj.m_minimumHeight),
                    m_maximumHeight(obj.m_maximumHeight) {}

            HeightImage::~HeightImage() {}

            HeightImage& HeightImage::operator=(const HeightImage &obj) {
                Image::operator=(obj);
                setGroundHeight(obj.getGroundHeight());
                setMinimumHeight(obj.getMinimumHeight());
                setMaximumHeight(obj.getMaximumHeight());
                return (*this);
            }

            void HeightImage::accept(ScenarioVisitor &visitor) {
                Image::accept(visitor);
                visitor.visit(*this);
            }

            double HeightImage::getGroundHeight() const {
                return m_groundHeight;
            }

            void HeightImage::setGroundHeight(const double &gh) {
                m_groundHeight = gh;
            }

            double HeightImage::getMinimumHeight() const {
                return m_minimumHeight;
            }

            void HeightImage::setMinimumHeight(const double &minH) {
                m_minimumHeight = minH;
            }

            double HeightImage::getMaximumHeight() const {
                return m_maximumHeight;
            }

            void HeightImage::setMaximumHeight(const double &maxH) {
                m_maximumHeight = maxH;
            }

            const string HeightImage::toString() const {
                stringstream s;
                s << Image::toString()
                << ", GroundHeight: " << m_groundHeight << ", MinimumHeight: " << m_minimumHeight << ", MaximumHeight: " << m_maximumHeight;
                return s.str();
            }

            ostream& HeightImage::operator<<(ostream &out) const {
                // Serializer super class.
                Image::operator<<(out);

                SerializationFactory sf;

                Serializer &s = sf.getSerializer(out);

                s.write(CRC32 < OPENDAVINCI_CORE_STRINGLITERAL7('g', 'r', 'o', 'u', 'n', 'd', 'h') >::RESULT,
                        m_groundHeight);

                s.write(CRC32 < OPENDAVINCI_CORE_STRINGLITERAL4('m', 'i', 'n', 'h') >::RESULT,
                        m_minimumHeight);

                s.write(CRC32 < OPENDAVINCI_CORE_STRINGLITERAL4('m', 'a', 'x', 'h') >::RESULT,
                        m_maximumHeight);

                return out;
            }

            istream& HeightImage::operator>>(istream &in) {
                // Deserializer super class.
                Image::operator>>(in);

                SerializationFactory sf;

                Deserializer &d = sf.getDeserializer(in);

                d.read(CRC32 < OPENDAVINCI_CORE_STRINGLITERAL7('g', 'r', 'o', 'u', 'n', 'd', 'h') >::RESULT,
                       m_groundHeight);

                d.read(CRC32 < OPENDAVINCI_CORE_STRINGLITERAL4('m', 'i', 'n', 'h') >::RESULT,
                       m_minimumHeight);

                d.read(CRC32 < OPENDAVINCI_CORE_STRINGLITERAL4('m', 'a', 'x', 'h') >::RESULT,
                       m_maximumHeight);

                return in;
            }

        }
    }
} // hesperia::data::scenario
