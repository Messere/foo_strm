#include "stdafx.h"

class strm : public playlist_loader
{
public:

	void open(const char * p_path, const service_ptr_t<file> & p_file, playlist_loader_callback::ptr p_callback, abort_callback & p_abort)
	{
		pfc::string8 url;

		p_callback->on_progress(p_path);
		p_file->seek(0, p_abort);  // required, said SDK
		p_file->read_string_raw(url, p_abort);

		console::printf("STRM: Found %s in strm file", url.c_str());

		if (!playlist_loader::g_try_load_playlist(NULL, url.c_str(), p_callback, p_abort)) {
			console::printf("STRM: %s does not look like a playlist, let's try to play it directly", url.c_str());

			metadb_handle_ptr f_handle;

			file_info_impl f_info;
			read_file_info(&f_info, p_path);

			p_callback->handle_create(f_handle, make_playable_location(url.c_str(), 0));
			p_callback->on_entry_info(f_handle, playlist_loader_callback::entry_user_requested, filestats_invalid, f_info, false);
		}
	}

	void write(const char * p_path, const service_ptr_t<file> & p_file, metadb_handle_list_cref p_data, abort_callback & p_abort)
	{
	}
	
	const char * get_extension()
	{
		return "strm";
	}

	bool can_write()
	{
		return false;
	}

	bool is_our_content_type(const char* p_content_type)
	{
		return false;
	}

	bool is_associatable()
	{
		return true;
	}

private:
	void read_file_info(file_info * p_file_info, const char * p_path)
	{
		// this shows something "nice" when strm file is loaded
		// a bit pointless, because it'll be overwritten after dynamic 
		// info from file is read.

		p_file_info->meta_set("artist", "Unknown");
		p_file_info->meta_set("album", "Stream");
		p_file_info->meta_set("title", pfc::string_filename(p_path).c_str());
		p_file_info->meta_set("tracknumber", "1");
	}
};

playlist_loader_factory_t<strm> strm_playlist;
