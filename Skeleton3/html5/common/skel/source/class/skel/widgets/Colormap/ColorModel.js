/**
 * Displays a file browser.
 */
/*global mImport */
/*******************************************************************************
 * @ignore( mImport)
 ******************************************************************************/

qx.Class.define("skel.widgets.Colormap.ColorModel", {
    extend : qx.ui.core.Widget,

    construct : function(  ) {
        this.base(arguments);
        this._init( );
    },

    members : {


        /**
         * Initializes the UI.
         */
        _init : function(  ) {
            var widgetLayout = new qx.ui.layout.VBox(2);
            this._setLayout(widgetLayout);
            
            var modelGroup = new qx.ui.groupbox.GroupBox( "Model");
            modelGroup.setLayout( new qx.ui.layout.VBox(2));
            
            this.m_gammaRadio = new qx.ui.form.RadioButton( "Gamma");
            this.m_logRadio = new qx.ui.form.RadioButton( "Logarithm");
            
            var modelRadio = new qx.ui.form.RadioGroup();
            modelRadio.add( this.m_gammaRadio, this.m_logRadio );
            
            modelGroup.add( this.m_gammaRadio );
            modelGroup.add( this.m_logRadio );
            this._add( modelGroup );
        },
        
        m_gammaRadio : null,
        m_logRadio : null
    }
});