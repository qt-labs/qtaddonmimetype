import Qt 4.7
import QtTest 1.0
import com.nokia.MimeTypes 1.0

TestCase {
    name: "tst_declarative_mimetypes"

    function pngMimeTypeName() {
        return "image/png"
    }

    function pngMimeTypeDisplayName() {
        return "PNG File";
    }

    function pngMimeTypeIconUrl() {
        return "/usr/share/icons/oxygen/64x64/mimetypes/image-x-generic.png"
    }

    function firstPngMimeTypeFileExtention() {
        return ".png"
    }

    MimeType {
        id: instantiatedPngMimeType
        name: pngMimeTypeName()
        displayName: pngMimeTypeDisplayName()
        iconUrl: pngMimeTypeIconUrl()
        fileExtentions: [ firstPngMimeTypeFileExtention() ]
    }

    MimeType {
        id: otherPngMimeType
    }

    MimeType {
        id: defaultMimeType
    }

    function test_MimeType_isValid() {
        compare(instantiatedPngMimeType.isValid, true)

        otherPngMimeType.assign(instantiatedPngMimeType)

        compare(otherPngMimeType.isValid, true)
        compare(instantiatedPngMimeType.equals(otherPngMimeType), true)
        compare(otherPngMimeType.equals(instantiatedPngMimeType), true)

        compare(defaultMimeType.isValid, false)
    }

    function test_MimeType_name() {
        otherPngMimeType.assign(instantiatedPngMimeType)
        otherPngMimeType.name = ""

        // Verify that the Id is part of the equality test:
        compare(instantiatedPngMimeType.name, pngMimeTypeName())

        compare(instantiatedPngMimeType.equals(otherPngMimeType), false)
    }

    function test_MimeType_displayName() {
        otherPngMimeType.assign(instantiatedPngMimeType)
        otherPngMimeType.displayName = ""

        // Verify that the Id is part of the equality test:
        compare(instantiatedPngMimeType.displayName, pngMimeTypeDisplayName())

        compare(instantiatedPngMimeType.equals(otherPngMimeType), false)
    }

    function test_MimeType_iconUrl() {
        otherPngMimeType.assign(instantiatedPngMimeType)
        otherPngMimeType.iconUrl = ""

        // Verify that the Id is part of the equality test:
        compare(instantiatedPngMimeType.iconUrl, pngMimeTypeIconUrl())

        compare(instantiatedPngMimeType.equals(otherPngMimeType), false)
    }

    function test_MimeType_fileExtentions() {
        otherPngMimeType.assign(instantiatedPngMimeType)
        otherPngMimeType.fileExtentions = []
        compare(otherPngMimeType.fileExtentions.length, 0)

        // Verify that the Id is part of the equality test:
        compare(instantiatedPngMimeType.fileExtentions.length, 1)
        compare(instantiatedPngMimeType.fileExtentions[0], ".png")

        compare(instantiatedPngMimeType.equals(otherPngMimeType), false)
    }

    function editServiceActionName() {
        return "edit";
    }

    function editServiceActionDisplayName() {
        return "Edit"
    }

    function editServiceActionIconUrl() {
        return "/dev/null"
    }

    ServiceAction {
        id: instantiatedEditServiceAction
        name: editServiceActionName()
        displayName: editServiceActionDisplayName()
        iconUrl: editServiceActionIconUrl()
    }

    ServiceAction {
        id: otherEditServiceAction
    }

    ServiceAction {
        id: defaultServiceAction
    }

    function test_ServiceAction_isValid() {
        compare(instantiatedEditServiceAction.isValid, true)

        otherEditServiceAction.assign(instantiatedEditServiceAction)

        compare(otherEditServiceAction.isValid, true)
        compare(instantiatedEditServiceAction.equals(otherEditServiceAction), true)
        compare(otherEditServiceAction.equals(instantiatedEditServiceAction), true)

        compare(defaultServiceAction.isValid, false)
    }

    function test_ServiceAction_name() {
        otherEditServiceAction.assign(instantiatedEditServiceAction)
        otherEditServiceAction.name = ""

        // Verify that the Id is part of the equality test:
        compare(instantiatedEditServiceAction.name, editServiceActionName())

        compare(instantiatedEditServiceAction.equals(otherEditServiceAction), false)
    }

    function test_ServiceAction_displayName() {
        otherEditServiceAction.assign(instantiatedEditServiceAction)
        otherEditServiceAction.displayName = ""

        // Verify that the Id is part of the equality test:
        compare(instantiatedEditServiceAction.displayName, editServiceActionDisplayName())

        compare(instantiatedEditServiceAction.equals(otherEditServiceAction), false)
    }

    function test_ServiceAction_iconUrl() {
        otherEditServiceAction.assign(instantiatedEditServiceAction)
        otherEditServiceAction.iconUrl = ""

        // Verify that the Id is part of the equality test:
        compare(instantiatedEditServiceAction.iconUrl, editServiceActionIconUrl())

        compare(instantiatedEditServiceAction.equals(otherEditServiceAction), false)
    }

    MimeTypeRegistry {
        id: mimeTypeRegistry
    }

    function test_MimeTypeRegistry_mimeTypes() {
        {
            var resultOfMimeTypes = mimeTypeRegistry.mimeTypes

            for (var mimeTypeNameIx = 0; mimeTypeNameIx < resultOfMimeTypes.length; ++mimeTypeNameIx) {
                //print(mimeTypeNameIx + ": " + resultOfMimeTypes[mimeTypeNameIx])
                mimeTypeRegistry.removeMimeType(resultOfMimeTypes[mimeTypeNameIx])
            }

            resultOfMimeTypes = mimeTypeRegistry.mimeTypes
            compare(resultOfMimeTypes.length, 0)
        }

        {
            // create
            mimeTypeRegistry.insertMimeType(instantiatedPngMimeType)

            var resultOfMimeTypes = mimeTypeRegistry.mimeTypes

            compare(resultOfMimeTypes.length, 1)
            compare(resultOfMimeTypes[0], pngMimeTypeName())
        }

        {
            // update
            mimeTypeRegistry.insertMimeType(instantiatedPngMimeType)

            var resultOfMimeTypes = mimeTypeRegistry.mimeTypes

            compare(resultOfMimeTypes.length, 1)
            compare(resultOfMimeTypes[0], pngMimeTypeName())
        }

        {
            mimeTypeRegistry.removeMimeType(pngMimeTypeName())

            var resultOfMimeTypes = mimeTypeRegistry.mimeTypes

            compare(resultOfMimeTypes.length, 0)
        }
    }

    function test_MimeTypeRegistry_findMimeType() {
        mimeTypeRegistry.insertMimeType(instantiatedPngMimeType)

        var resultOfFindMimeType = mimeTypeRegistry.findMimeType(pngMimeTypeName())

        compare(resultOfFindMimeType.isValid, true)
        compare(resultOfFindMimeType.equals(instantiatedPngMimeType), true)
    }

    function test_MimeTypeRegistry_fileExtentions() {
        mimeTypeRegistry.insertMimeType(instantiatedPngMimeType)

        var resultOfFileExtentions = mimeTypeRegistry.fileExtentions

        compare(resultOfFileExtentions.length, 1)
        compare(resultOfFileExtentions[0], firstPngMimeTypeFileExtention())
    }

    function test_MimeTypeRegistry_extractFileExtention() {
        mimeTypeRegistry.insertMimeType(instantiatedPngMimeType)

        var pngFileName = 'image' + firstPngMimeTypeFileExtention()

        var resultOfExtractFileExtention = mimeTypeRegistry.extractFileExtention(pngFileName)

        compare(resultOfExtractFileExtention, firstPngMimeTypeFileExtention())
    }

    function test_MimeTypeRegistry_findMimeTypes() {
        mimeTypeRegistry.insertMimeType(instantiatedPngMimeType)

        var resultOfFindMimeTypes = mimeTypeRegistry.findMimeTypes(firstPngMimeTypeFileExtention())

        compare(resultOfFindMimeTypes.length, 1)
        compare(resultOfFindMimeTypes[0], pngMimeTypeName())
    }

    function test_MimeTypeRegistry_determineMimeType() {
        mimeTypeRegistry.insertMimeType(instantiatedPngMimeType)

        // TODO Implement test_MimeTypeRegistry_determineMimeType()
        compare('Not implemented!', '')
    }

    function test_MimeTypeRegistry_serviceActions() {
        {
            var resultOfServiceActions = mimeTypeRegistry.serviceActions;

            for (var serviceActionNameIx = 0; serviceActionNameIx < resultOfServiceActions.length; ++serviceActionNameIx) {
                //print(serviceActionNameIx + ": " + resultOfServiceActions[serviceActionNameIx])
                mimeTypeRegistry.removeServiceAction(resultOfServiceActions[serviceActionNameIx])
            }

            resultOfServiceActions = mimeTypeRegistry.serviceActions
            compare(resultOfServiceActions.length, 0)
        }

        {
            // create
            mimeTypeRegistry.insertServiceAction(instantiatedEditServiceAction)

            var resultOfServiceActions = mimeTypeRegistry.serviceActions

            compare(resultOfServiceActions.length, 1)
            compare(resultOfServiceActions[0], editServiceActionName())
        }

        {
            // update
            mimeTypeRegistry.insertServiceAction(instantiatedEditServiceAction)

            var resultOfServiceActions = mimeTypeRegistry.serviceActions

            compare(resultOfServiceActions.length, 1)
            compare(resultOfServiceActions[0], editServiceActionName())
        }

        {
            mimeTypeRegistry.removeServiceAction(editServiceActionName())

            var resultOfServiceActions = mimeTypeRegistry.serviceActions

            compare(resultOfServiceActions.length, 0)
        }
    }

    function test_MimeTypeRegistry_findServiceAction() {
        mimeTypeRegistry.insertServiceAction(instantiatedEditServiceAction)

        var resultOfFindServiceAction = mimeTypeRegistry.findServiceAction(editServiceActionName())

        compare(resultOfFindServiceAction.isValid, true)
        compare(resultOfFindServiceAction.equals(instantiatedEditServiceAction), true)
    }

    function test_MimeTypeRegistry_setUserAlwaysSelectsApplication() {
        mimeTypeRegistry.insertServiceAction(instantiatedEditServiceAction)

        mimeTypeRegistry.setUserAlwaysSelectsApplication (
                             editServiceActionName(), pngMimeTypeName(), true
                         )

        compare(mimeTypeRegistry.userAlwaysSelectsApplication(editServiceActionName(), pngMimeTypeName()), true)

        mimeTypeRegistry.setUserAlwaysSelectsApplication (
                             editServiceActionName(), pngMimeTypeName(), false
                         )

        compare(!mimeTypeRegistry.userAlwaysSelectsApplication(editServiceActionName(), pngMimeTypeName()), true)
    }

    function shareOnPicasaWebAlbumsName() { return 'shareOnPicasaWebAlbums' }
    function shareOnPicasaWebAlbumsDisplayName() { return 'Share on Picasa Web Albums' }
    function shareOnPicasaWebAlbumsIconUrl() { return '/dev/null' }

    ServiceAction {
        id: shareOnPicasaWebAlbumsServiceAction
        name: shareOnPicasaWebAlbumsName()
        displayName: shareOnPicasaWebAlbumsDisplayName()
        iconUrl: shareOnPicasaWebAlbumsIconUrl()
    }

    function test_MimeTypeRegistry_findApplications() {
        mimeTypeRegistry.insertServiceAction(instantiatedEditServiceAction)
        mimeTypeRegistry.insertServiceAction(shareOnPicasaWebAlbumsServiceAction)
        mimeTypeRegistry.insertMimeType(instantiatedPngMimeType)

        var gwenviewApplicationId = 'gwenview'
        var showimgApplicationId = 'showimg'

        {
            var resultOfFindApplications = mimeTypeRegistry.findApplications(pngMimeTypeName())
            for (var ix = 0; ix < resultOfFindApplications.length; ++ix) {
                if (resultOfFindApplications[ix].length != 2) {
                    print("Error: resultOfFindApplications[" + ix + "].length: " + resultOfFindApplications[ix].length)
                    continue
                }

                //print("application: " + resultOfFindApplications[ix][0] + ", action: " + resultOfFindApplications[ix][1])
                mimeTypeRegistry.unregisterApplication(resultOfFindApplications[ix][0])
            }
            resultOfFindApplications = mimeTypeRegistry.findApplications(pngMimeTypeName())
            compare(resultOfFindApplications.length, 0)
        }

        mimeTypeRegistry.registerApplication(gwenviewApplicationId, editServiceActionName(), pngMimeTypeName())

        var resultOfFindApplications1 = mimeTypeRegistry.findApplications(pngMimeTypeName())

        compare(resultOfFindApplications1.length, 1)
        compare(resultOfFindApplications1[0][0], gwenviewApplicationId)
        compare(resultOfFindApplications1[0][1], editServiceActionName())

        var resultOfFindApplications2 = mimeTypeRegistry.findApplications(editServiceActionName(), pngMimeTypeName())

        compare(resultOfFindApplications2.length, 1)
        compare(resultOfFindApplications2[0], gwenviewApplicationId)

        // ----------------------------------------------------------------------------------------

        mimeTypeRegistry.registerApplication(gwenviewApplicationId, shareOnPicasaWebAlbumsName(), pngMimeTypeName())

        resultOfFindApplications1 = mimeTypeRegistry.findApplications(pngMimeTypeName())

        compare(resultOfFindApplications1.length, 2)
        compare(resultOfFindApplications1[0][0], gwenviewApplicationId)
        compare(resultOfFindApplications1[0][1], editServiceActionName())
        compare(resultOfFindApplications1[1][0], gwenviewApplicationId)
        compare(resultOfFindApplications1[1][1], shareOnPicasaWebAlbumsName())

        resultOfFindApplications2 = mimeTypeRegistry.findApplications(editServiceActionName(), pngMimeTypeName())

        compare(resultOfFindApplications2.length, 1)
        compare(resultOfFindApplications2[0], gwenviewApplicationId)

        resultOfFindApplications2 = mimeTypeRegistry.findApplications(shareOnPicasaWebAlbumsName(), pngMimeTypeName())

        compare(resultOfFindApplications2.length, 1)
        compare(resultOfFindApplications2[0], gwenviewApplicationId)

        // ----------------------------------------------------------------------------------------

        mimeTypeRegistry.registerApplication(showimgApplicationId, editServiceActionName(), pngMimeTypeName())

        resultOfFindApplications1 = mimeTypeRegistry.findApplications(pngMimeTypeName())

        compare(resultOfFindApplications1.length, 3)
        compare(resultOfFindApplications1[0][0], showimgApplicationId)
        compare(resultOfFindApplications1[0][1], editServiceActionName())   // edit is before share
        compare(resultOfFindApplications1[1][0], gwenviewApplicationId)
        compare(resultOfFindApplications1[1][1], shareOnPicasaWebAlbumsName())
        compare(resultOfFindApplications1[2][0], gwenviewApplicationId)    // priority #2
        compare(resultOfFindApplications1[2][1], editServiceActionName())

        resultOfFindApplications2 = mimeTypeRegistry.findApplications(editServiceActionName(), pngMimeTypeName())

        compare(resultOfFindApplications2.length, 2)
        compare(resultOfFindApplications2[0], showimgApplicationId)
        compare(resultOfFindApplications2[1], gwenviewApplicationId)

        resultOfFindApplications2 = mimeTypeRegistry.findApplications(shareOnPicasaWebAlbumsName(), pngMimeTypeName())

        compare(resultOfFindApplications2.length, 1)
        compare(resultOfFindApplications2[0], gwenviewApplicationId)

        // ----------------------------------------------------------------------------------------

        mimeTypeRegistry.increaseApplicationPreference(gwenviewApplicationId, editServiceActionName(), pngMimeTypeName())

        resultOfFindApplications1 = mimeTypeRegistry.findApplications(pngMimeTypeName())

        compare(resultOfFindApplications1.length, 3)
        compare(resultOfFindApplications1[0][0], gwenviewApplicationId)
        compare(resultOfFindApplications1[0][1], editServiceActionName())
        compare(resultOfFindApplications1[1][0], gwenviewApplicationId)
        compare(resultOfFindApplications1[1][1], shareOnPicasaWebAlbumsName())
        compare(resultOfFindApplications1[2][0], showimgApplicationId)
        compare(resultOfFindApplications1[2][1], editServiceActionName())

        resultOfFindApplications2 = mimeTypeRegistry.findApplications(editServiceActionName(), pngMimeTypeName())

        compare(resultOfFindApplications2.length, 2)
        compare(resultOfFindApplications2[0], gwenviewApplicationId)
        compare(resultOfFindApplications2[1], showimgApplicationId)

        resultOfFindApplications2 = mimeTypeRegistry.findApplications(shareOnPicasaWebAlbumsName(), pngMimeTypeName())

        compare(resultOfFindApplications2.length, 1)
        compare(resultOfFindApplications2[0], gwenviewApplicationId)

        // ----------------------------------------------------------------------------------------

        mimeTypeRegistry.decreaseApplicationPreference(gwenviewApplicationId, editServiceActionName(), pngMimeTypeName())

        resultOfFindApplications1 = mimeTypeRegistry.findApplications(pngMimeTypeName())

        compare(resultOfFindApplications1.length, 3)
        compare(resultOfFindApplications1[0][0], showimgApplicationId)
        compare(resultOfFindApplications1[0][1], editServiceActionName())   // edit is before share
        compare(resultOfFindApplications1[1][0], gwenviewApplicationId)
        compare(resultOfFindApplications1[1][1], shareOnPicasaWebAlbumsName())
        compare(resultOfFindApplications1[2][0], gwenviewApplicationId)    // priority #2
        compare(resultOfFindApplications1[2][1], editServiceActionName())

        resultOfFindApplications2 = mimeTypeRegistry.findApplications(editServiceActionName(), pngMimeTypeName())

        compare(resultOfFindApplications2.length, 2)
        compare(resultOfFindApplications2[0], showimgApplicationId)
        compare(resultOfFindApplications2[1], gwenviewApplicationId)

        resultOfFindApplications2 = mimeTypeRegistry.findApplications(shareOnPicasaWebAlbumsName(), pngMimeTypeName())

        compare(resultOfFindApplications2.length, 1)
        compare(resultOfFindApplications2[0], gwenviewApplicationId)

        // ----------------------------------------------------------------------------------------

        mimeTypeRegistry.setUserAlwaysSelectsApplication(editServiceActionName(), pngMimeTypeName(), false)

        mimeTypeRegistry.unregisterApplication(showimgApplicationId)

        compare(mimeTypeRegistry.userAlwaysSelectsApplication(editServiceActionName(), pngMimeTypeName()), true)

        resultOfFindApplications1 = mimeTypeRegistry.findApplications(pngMimeTypeName())

        compare(resultOfFindApplications1.length, 2)
        compare(resultOfFindApplications1[0][0], gwenviewApplicationId)
        compare(resultOfFindApplications1[0][1], editServiceActionName())   // edit is before share
        compare(resultOfFindApplications1[1][0], gwenviewApplicationId)
        compare(resultOfFindApplications1[1][1], shareOnPicasaWebAlbumsName())

        resultOfFindApplications2 = mimeTypeRegistry.findApplications(editServiceActionName(), pngMimeTypeName())

        compare(resultOfFindApplications2.length, 1)
        compare(resultOfFindApplications2[0], gwenviewApplicationId)

        resultOfFindApplications2 = mimeTypeRegistry.findApplications(shareOnPicasaWebAlbumsName(), pngMimeTypeName())

        compare(resultOfFindApplications2.length, 1)
        compare(resultOfFindApplications2[0], gwenviewApplicationId)
    }
}
