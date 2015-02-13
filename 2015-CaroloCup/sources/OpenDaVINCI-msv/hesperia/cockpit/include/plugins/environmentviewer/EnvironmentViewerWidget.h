/*
 * Copyright (c) Christian Berger and Bernhard Rumpe, Rheinisch-Westfaelische Technische Hochschule Aachen, Germany.
 *
 * The Hesperia Framework.
 */

#ifndef PLUGINS_ENVIRONMENTVIEWER_ENVIRONMENTVIEWERWIDGET_H_
#define PLUGINS_ENVIRONMENTVIEWER_ENVIRONMENTVIEWERWIDGET_H_

#include <map>
#include <string>

#include "QtIncludes.h"

#include "core/base/Mutex.h"
#include "core/base/TreeNode.h"
#include "core/wrapper/StringComparator.h"

#include "plugins/GLControlFrame.h"
#include "plugins/environmentviewer/CameraAssignableNodesListener.h"
#include "plugins/environmentviewer/EnvironmentViewerGLWidget.h"
#include "plugins/environmentviewer/SelectableNodeDescriptor.h"
#include "plugins/environmentviewer/SelectableNodeDescriptorTreeListener.h"

namespace cockpit {
    namespace plugins {
        namespace environmentviewer {

            /**
             * This class is the outer container for the 3D scene graph viewer
             * implemented in EnvironmentViewerGLWidget and a tree like data
             * structure on its right hand side.
             */
            class EnvironmentViewerWidget : public QWidget, public core::io::ContainerListener, public CameraAssignableNodesListener, public SelectableNodeDescriptorTreeListener {

                Q_OBJECT

                private:
                    /**
                     * "Forbidden" copy constructor. Goal: The compiler should warn
                     * already at compile time for unwanted bugs caused by any misuse
                     * of the copy constructor.
                     */
                    EnvironmentViewerWidget(const EnvironmentViewerWidget &/*obj*/);

                    /**
                     * "Forbidden" assignment operator. Goal: The compiler should warn
                     * already at compile time for unwanted bugs caused by any misuse
                     * of the assignment operator.
                     */
                    EnvironmentViewerWidget& operator=(const EnvironmentViewerWidget &/*obj*/);

                public:
                    /**
                     * Constructor.
                     *
                     * @param plugIn Reference to the plugin to which this widget belongs.
                     * @param prnt Pointer to the parental widget.
                     */
                    EnvironmentViewerWidget(const PlugIn &plugIn, QWidget *prnt);

                    virtual ~EnvironmentViewerWidget();

                    virtual void nextContainer(core::data::Container &c);

                    virtual void update(core::base::TreeNode<SelectableNodeDescriptor> *node);

                    virtual void updateListOfCameraAssignableNodes(const vector<hesperia::threeD::NodeDescriptor> &list);

                private slots:
                    /**
                     * This method is called whenever an item in the list changes
                     * its state.
                     *
                     * @param item Item that changed.
                     * @param column Number of column.
                     */
                    void itemChanged(QTreeWidgetItem *item, int column);

                    /**
                     * This method is called whenever an item in the combobox
                     * for the assignable camera changes its state.
                     *
                     * @param item Item that changed.
                     */
                    void selectedItemChanged(const QString &item);

                    /**
                     * This method is called whenever an item in the combobox
                     * for the color of the background changes its state.
                     *
                     * @param item Item that changed.
                     */
                    void selectedItemChangedBackground(const QString &item);

                private:
                    GLControlFrame *m_viewerControlWidget;
                    EnvironmentViewerGLWidget *m_environmentViewerGLWidget;

                    QComboBox *m_cameraSelector;
                    core::base::Mutex m_cameraAssignableNodesUpdateMutex;
                    bool m_cameraAssignableNodesUpdate;
                    map<string, hesperia::threeD::NodeDescriptor, core::wrapper::StringComparator> m_mapOfNodeDescriptors;

                    QComboBox *m_backgroundSelector;

                    QTreeWidget *m_textualSceneGraph;
                    core::base::Mutex m_textualSceneGraphRootUpdateMutex;
                    bool m_textualSceneGraphRootUpdate;
                    core::base::Mutex m_selectableNodeDescriptorTreeMutex;
                    core::base::TreeNode<SelectableNodeDescriptor> *m_selectableNodeDescriptorTree;

                    /**
                     * This method updates the tree of SelectableNodeDescriptors.
                     *
                     * @param name name of the NodeDescriptor to be updated.
                     * @param enabled True if the NodeDescriptor is enabled.
                     */
                    void updateEntry(core::base::TreeNode<SelectableNodeDescriptor> *node, const string &name, const bool &enabled);
            };
        }
    }
} // plugins::environmentviewer

#endif /*PLUGINS_ENVIRONMENTVIEWER_ENVIRONMENTVIEWERWIDGET_H_*/
