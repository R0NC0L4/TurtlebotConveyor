// Copyright 2019-2021 The MathWorks, Inc.
// Common copy functions for conveyor_description_pkg/conveyor_state
#include "boost/date_time.hpp"
#include "boost/shared_array.hpp"
#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable : 4244)
#pragma warning(disable : 4265)
#pragma warning(disable : 4458)
#pragma warning(disable : 4100)
#pragma warning(disable : 4127)
#pragma warning(disable : 4267)
#pragma warning(disable : 4068)
#pragma warning(disable : 4245)
#else
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpedantic"
#pragma GCC diagnostic ignored "-Wunused-local-typedefs"
#pragma GCC diagnostic ignored "-Wredundant-decls"
#pragma GCC diagnostic ignored "-Wnon-virtual-dtor"
#pragma GCC diagnostic ignored "-Wdelete-non-virtual-dtor"
#pragma GCC diagnostic ignored "-Wunused-parameter"
#pragma GCC diagnostic ignored "-Wunused-variable"
#pragma GCC diagnostic ignored "-Wshadow"
#endif //_MSC_VER
#include "ros/ros.h"
#include "conveyor_description_pkg/conveyor_state.h"
#include "visibility_control.h"
#include "MATLABROSMsgInterface.hpp"
#include "ROSPubSubTemplates.hpp"
class CONVEYOR_DESCRIPTION_PKG_EXPORT conveyor_description_pkg_msg_conveyor_state_common : public MATLABROSMsgInterface<conveyor_description_pkg::conveyor_state> {
  public:
    virtual ~conveyor_description_pkg_msg_conveyor_state_common(){}
    virtual void copy_from_struct(conveyor_description_pkg::conveyor_state* msg, const matlab::data::Struct& arr, MultiLibLoader loader); 
    //----------------------------------------------------------------------------
    virtual MDArray_T get_arr(MDFactory_T& factory, const conveyor_description_pkg::conveyor_state* msg, MultiLibLoader loader, size_t size = 1);
};
  void conveyor_description_pkg_msg_conveyor_state_common::copy_from_struct(conveyor_description_pkg::conveyor_state* msg, const matlab::data::Struct& arr,
               MultiLibLoader loader) {
    try {
        //wheel_lr
        const matlab::data::TypedArray<float> wheel_lr_arr = arr["WheelLr"];
        msg->wheel_lr = wheel_lr_arr[0];
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'WheelLr' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'WheelLr' is wrong type; expected a single.");
    }
    try {
        //wheel_rr
        const matlab::data::TypedArray<float> wheel_rr_arr = arr["WheelRr"];
        msg->wheel_rr = wheel_rr_arr[0];
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'WheelRr' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'WheelRr' is wrong type; expected a single.");
    }
    try {
        //wheel_lf
        const matlab::data::TypedArray<float> wheel_lf_arr = arr["WheelLf"];
        msg->wheel_lf = wheel_lf_arr[0];
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'WheelLf' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'WheelLf' is wrong type; expected a single.");
    }
    try {
        //wheel_rf
        const matlab::data::TypedArray<float> wheel_rf_arr = arr["WheelRf"];
        msg->wheel_rf = wheel_rf_arr[0];
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'WheelRf' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'WheelRf' is wrong type; expected a single.");
    }
    try {
        //joint_lr
        const matlab::data::TypedArray<float> joint_lr_arr = arr["JointLr"];
        msg->joint_lr = joint_lr_arr[0];
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'JointLr' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'JointLr' is wrong type; expected a single.");
    }
    try {
        //joint_rr
        const matlab::data::TypedArray<float> joint_rr_arr = arr["JointRr"];
        msg->joint_rr = joint_rr_arr[0];
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'JointRr' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'JointRr' is wrong type; expected a single.");
    }
    try {
        //joint_lf
        const matlab::data::TypedArray<float> joint_lf_arr = arr["JointLf"];
        msg->joint_lf = joint_lf_arr[0];
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'JointLf' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'JointLf' is wrong type; expected a single.");
    }
    try {
        //joint_rf
        const matlab::data::TypedArray<float> joint_rf_arr = arr["JointRf"];
        msg->joint_rf = joint_rf_arr[0];
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'JointRf' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'JointRf' is wrong type; expected a single.");
    }
  }
  //----------------------------------------------------------------------------
  MDArray_T conveyor_description_pkg_msg_conveyor_state_common::get_arr(MDFactory_T& factory, const conveyor_description_pkg::conveyor_state* msg,
       MultiLibLoader loader, size_t size) {
    auto outArray = factory.createStructArray({size,1},{"MessageType","WheelLr","WheelRr","WheelLf","WheelRf","JointLr","JointRr","JointLf","JointRf"});
    for(size_t ctr = 0; ctr < size; ctr++){
    outArray[ctr]["MessageType"] = factory.createCharArray("conveyor_description_pkg/conveyor_state");
    // wheel_lr
    auto currentElement_wheel_lr = (msg + ctr)->wheel_lr;
    outArray[ctr]["WheelLr"] = factory.createScalar(currentElement_wheel_lr);
    // wheel_rr
    auto currentElement_wheel_rr = (msg + ctr)->wheel_rr;
    outArray[ctr]["WheelRr"] = factory.createScalar(currentElement_wheel_rr);
    // wheel_lf
    auto currentElement_wheel_lf = (msg + ctr)->wheel_lf;
    outArray[ctr]["WheelLf"] = factory.createScalar(currentElement_wheel_lf);
    // wheel_rf
    auto currentElement_wheel_rf = (msg + ctr)->wheel_rf;
    outArray[ctr]["WheelRf"] = factory.createScalar(currentElement_wheel_rf);
    // joint_lr
    auto currentElement_joint_lr = (msg + ctr)->joint_lr;
    outArray[ctr]["JointLr"] = factory.createScalar(currentElement_joint_lr);
    // joint_rr
    auto currentElement_joint_rr = (msg + ctr)->joint_rr;
    outArray[ctr]["JointRr"] = factory.createScalar(currentElement_joint_rr);
    // joint_lf
    auto currentElement_joint_lf = (msg + ctr)->joint_lf;
    outArray[ctr]["JointLf"] = factory.createScalar(currentElement_joint_lf);
    // joint_rf
    auto currentElement_joint_rf = (msg + ctr)->joint_rf;
    outArray[ctr]["JointRf"] = factory.createScalar(currentElement_joint_rf);
    }
    return std::move(outArray);
  } 
class CONVEYOR_DESCRIPTION_PKG_EXPORT conveyor_description_pkg_conveyor_state_message : public ROSMsgElementInterfaceFactory {
  public:
    virtual ~conveyor_description_pkg_conveyor_state_message(){}
    virtual std::shared_ptr<MATLABPublisherInterface> generatePublisherInterface(ElementType type);
    virtual std::shared_ptr<MATLABSubscriberInterface> generateSubscriberInterface(ElementType type);
    virtual std::shared_ptr<MATLABRosbagWriterInterface> generateRosbagWriterInterface(ElementType type);
};  
  std::shared_ptr<MATLABPublisherInterface> 
          conveyor_description_pkg_conveyor_state_message::generatePublisherInterface(ElementType type){
    if(type != eMessage){
        throw std::invalid_argument("Wrong input, Expected eMessage");
    }
    return std::make_shared<ROSPublisherImpl<conveyor_description_pkg::conveyor_state,conveyor_description_pkg_msg_conveyor_state_common>>();
  }
  std::shared_ptr<MATLABSubscriberInterface> 
         conveyor_description_pkg_conveyor_state_message::generateSubscriberInterface(ElementType type){
    if(type != eMessage){
        throw std::invalid_argument("Wrong input, Expected eMessage");
    }
    return std::make_shared<ROSSubscriberImpl<conveyor_description_pkg::conveyor_state,conveyor_description_pkg::conveyor_state::ConstPtr,conveyor_description_pkg_msg_conveyor_state_common>>();
  }
#include "ROSbagTemplates.hpp" 
  std::shared_ptr<MATLABRosbagWriterInterface>
         conveyor_description_pkg_conveyor_state_message::generateRosbagWriterInterface(ElementType type){
    if(type != eMessage){
        throw std::invalid_argument("Wrong input, Expected eMessage");
    }
    return std::make_shared<ROSBagWriterImpl<conveyor_description_pkg::conveyor_state,conveyor_description_pkg_msg_conveyor_state_common>>();
  }
#include "register_macro.hpp"
// Register the component with class_loader.
// This acts as a sort of entry point, allowing the component to be discoverable when its library
// is being loaded into a running process.
CLASS_LOADER_REGISTER_CLASS(conveyor_description_pkg_msg_conveyor_state_common, MATLABROSMsgInterface<conveyor_description_pkg::conveyor_state>)
CLASS_LOADER_REGISTER_CLASS(conveyor_description_pkg_conveyor_state_message, ROSMsgElementInterfaceFactory)
#ifdef _MSC_VER
#pragma warning(pop)
#else
#pragma GCC diagnostic pop
#endif //_MSC_VER
//gen-1