type synthetic('a) = ReactEvent.synthetic('a);

module MakeSyntheticWrapper = (Type: {type t;}) => {
  [@bs.get] external bubbles : Type.t => bool = "";
  [@bs.get] external cancelable : Type.t => bool = "";
  [@bs.get] external currentTarget : Type.t => Dom.element = ""; /* Should return Dom.evetTarget */
  [@bs.get] external defaultPrevented : Type.t => bool = "";
  [@bs.get] external eventPhase : Type.t => int = "";
  [@bs.get] external isTrusted : Type.t => bool = "";
  [@bs.get] external nativeEvent : Type.t => Js.t({..}) = ""; /* Should return Dom.event */
  [@bs.send.pipe: Type.t] external preventDefault : unit = "";
  [@bs.send.pipe: Type.t] external isDefaultPrevented : bool = "";
  [@bs.send.pipe: Type.t] external stopPropagation : unit = "";
  [@bs.send.pipe: Type.t] external isPropagationStopped : bool = "";
  [@bs.get] external target : Type.t => Dom.element = ""; /* Should return Dom.evetTarget */
  [@bs.get] external timeStamp : Type.t => float = "";
  [@bs.get] external _type : Type.t => string = "type";
  [@bs.send.pipe: Type.t] external persist : unit = "";
};

module Synthetic = {
  type tag = ReactEvent.Synthetic.tag;
  type t = ReactEvent.Synthetic.t;
  [@bs.get] external bubbles : synthetic('a) => bool = "";
  [@bs.get] external cancelable : synthetic('a) => bool = "";
  [@bs.get] external currentTarget : synthetic('a) => Dom.element = ""; /* Should return Dom.evetTarget */
  [@bs.get] external defaultPrevented : synthetic('a) => bool = "";
  [@bs.get] external eventPhase : synthetic('a) => int = "";
  [@bs.get] external isTrusted : synthetic('a) => bool = "";
  [@bs.get] external nativeEvent : synthetic('a) => Js.t({..}) = ""; /* Should return Dom.event */
  [@bs.send.pipe: synthetic('a)] external preventDefault : unit = "";
  [@bs.send.pipe: synthetic('a)] external isDefaultPrevented : bool = "";
  [@bs.send.pipe: synthetic('a)] external stopPropagation : unit = "";
  [@bs.send.pipe: synthetic('a)] external isPropagationStopped : bool = "";
  [@bs.get] external target : synthetic('a) => Dom.element = ""; /* Should return Dom.evetTarget */
  [@bs.get] external timeStamp : synthetic('a) => float = "";
  [@bs.get] external _type : synthetic('a) => string = "type";
  [@bs.send.pipe: synthetic('a)] external persist : unit = "";
};

/* Cast any event type to the general synthetic type. This is safe, since synthetic is more general */
external toSyntheticEvent : synthetic('a) => Synthetic.t = "%identity";

module Clipboard = {
  type tag = ReactEvent.Clipboard.tag;
  type t = ReactEvent.Clipboard.t;
  include
    MakeSyntheticWrapper(
      {
        type nonrec t = t;
      },
    );
  [@bs.get] external clipboardData : t => Js.t({..}) = ""; /* Should return Dom.dataTransfer */
};

module Composition = {
  type tag = ReactEvent.Composition.tag;
  type t = ReactEvent.Composition.t;
  include
    MakeSyntheticWrapper(
      {
        type nonrec t = t;
      },
    );
  [@bs.get] external data : t => string = "";
};

module Keyboard = {
  type tag = ReactEvent.Keyboard.tag;
  type t = ReactEvent.Keyboard.t;
  include
    MakeSyntheticWrapper(
      {
        type nonrec t = t;
      },
    );
  [@bs.get] external altKey : t => bool = "";
  [@bs.get] external charCode : t => int = "";
  [@bs.get] external ctrlKey : t => bool = "";
  [@bs.send.pipe: t] external getModifierState : string => bool = "";
  [@bs.get] external key : t => string = "";
  [@bs.get] external keyCode : t => int = "";
  [@bs.get] external locale : t => string = "";
  [@bs.get] external location : t => int = "";
  [@bs.get] external metaKey : t => bool = "";
  [@bs.get] external repeat : t => bool = "";
  [@bs.get] external shiftKey : t => bool = "";
  [@bs.get] external which : t => int = "";
};

module Focus = {
  type tag = ReactEvent.Focus.tag;
  type t = ReactEvent.Focus.t;
  include
    MakeSyntheticWrapper(
      {
        type nonrec t = t;
      },
    );
  [@bs.get] external relatedTarget : t => Dom.element = ""; /* Should return Dom.eventTarget */
};

module Form = {
  type tag = ReactEvent.Form.tag;
  type t = ReactEvent.Form.t;
  include
    MakeSyntheticWrapper(
      {
        type nonrec t = t;
      },
    );
};

module Mouse = {
  type tag = ReactEvent.Mouse.tag;
  type t = ReactEvent.Mouse.t;
  include
    MakeSyntheticWrapper(
      {
        type nonrec t = t;
      },
    );
  [@bs.get] external altKey : t => bool = "";
  [@bs.get] external button : t => int = "";
  [@bs.get] external buttons : t => int = "";
  [@bs.get] external clientX : t => int = "";
  [@bs.get] external clientY : t => int = "";
  [@bs.get] external ctrlKey : t => bool = "";
  [@bs.send.pipe: t] external getModifierState : string => bool = "";
  [@bs.get] external metaKey : t => bool = "";
  [@bs.get] external pageX : t => int = "";
  [@bs.get] external pageY : t => int = "";
  [@bs.get] external relatedTarget : t => Dom.element = ""; /* Should return Dom.eventTarget */
  [@bs.get] external screenX : t => int = "";
  [@bs.get] external screenY : t => int = "";
  [@bs.get] external shiftKey : t => bool = "";
};

module Selection = {
  type tag = ReactEvent.Selection.tag;
  type t = ReactEvent.Selection.t;
  include
    MakeSyntheticWrapper(
      {
        type nonrec t = t;
      },
    );
};

module Touch = {
  type tag = ReactEvent.Touch.tag;
  type t = ReactEvent.Touch.t;
  include
    MakeSyntheticWrapper(
      {
        type nonrec t = t;
      },
    );
  [@bs.get] external altKey : t => bool = "";
  [@bs.get] external changedTouches : t => Js.t({..}) = ""; /* Should return Dom.touchList */
  [@bs.get] external ctrlKey : t => bool = "";
  [@bs.send.pipe: t] external getModifierState : string => bool = "";
  [@bs.get] external metaKey : t => bool = "";
  [@bs.get] external shiftKey : t => bool = "";
  [@bs.get] external targetTouches : t => Js.t({..}) = ""; /* Should return Dom.touchList */
  [@bs.get] external touches : t => Js.t({..}) = ""; /* Should return Dom.touchList */
};

module UI = {
  type tag = ReactEvent.UI.tag;
  type t = ReactEvent.UI.t;
  include
    MakeSyntheticWrapper(
      {
        type nonrec t = t;
      },
    );
  [@bs.get] external detail : t => int = "";
  [@bs.get] external view : t => Dom.window = ""; /* Should return DOMAbstractView/WindowProxy */
};

module Wheel = {
  type tag = ReactEvent.Wheel.tag;
  type t = ReactEvent.Wheel.t;
  include
    MakeSyntheticWrapper(
      {
        type nonrec t = t;
      },
    );
  [@bs.get] external deltaMode : t => int = "";
  [@bs.get] external deltaX : t => float = "";
  [@bs.get] external deltaY : t => float = "";
  [@bs.get] external deltaZ : t => float = "";
};

module Media = {
  type tag = ReactEvent.Media.tag;
  type t = ReactEvent.Media.t;
  include
    MakeSyntheticWrapper(
      {
        type nonrec t = t;
      },
    );
};

module Image = {
  type tag = ReactEvent.Image.tag;
  type t = ReactEvent.Image.t;
  include
    MakeSyntheticWrapper(
      {
        type nonrec t = t;
      },
    );
};

module Animation = {
  type tag = ReactEvent.Animation.tag;
  type t = ReactEvent.Animation.t;
  include
    MakeSyntheticWrapper(
      {
        type nonrec t = t;
      },
    );
  [@bs.get] external animationName : t => string = "";
  [@bs.get] external pseudoElement : t => string = "";
  [@bs.get] external elapsedTime : t => float = "";
};

module Transition = {
  type tag = ReactEvent.Transition.tag;
  type t = ReactEvent.Transition.t;
  include
    MakeSyntheticWrapper(
      {
        type nonrec t = t;
      },
    );
  [@bs.get] external propertyName : t => string = "";
  [@bs.get] external pseudoElement : t => string = "";
  [@bs.get] external elapsedTime : t => float = "";
};
